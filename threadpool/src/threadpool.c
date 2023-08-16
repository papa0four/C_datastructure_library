/**
 * @file threadpool.c
 * @author James M. Horne (jamesmhorne90@gmail.com)
 * @brief A Threadpool data structure. Starts a determined amount of pthreads
 *          that continously wait for a 'job'. A job consists of a function
 *          pointer with a signature defined in threadpool.h. The user is
 *          responsible for how a 'job' behaves; if there is no functionality
 *          within that function to stop execution when the b_run flag is set
 *          to false, then the threadpool will not shutdown properly until the
 *          function is complete. The max threads that can be created is at
 *          the cross of max size_t and what the host machine can handle.
 * @version 0.1
 * @date 2021-12-31
 */

#include <pthread.h>
#include <stdlib.h>
#include "../include/threadpool.h"

/*** structure definitions ***/

typedef struct job_t job_t;

typedef struct job_t
{
    job_f   p_job_func;
    void *  p_data;
    job_t * p_next;
} job_t;

typedef struct signal_t
{
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    _Atomic bool    b_run;
} signal_t;

typedef struct threadpool_t
{
    pthread_t * p_threads;
    size_t      thread_count;
    job_t *     p_jobs_head;
    job_t *     p_jobs_tail;
    signal_t *  p_signals;
} threadpool_t;

/*** private function prototypes ***/
static signal_t *
init_signals (void);

static void
destroy_signals (signal_t ** pp_signals);

static void *
handle_jobs (threadpool_t * p_threadpool);

static bool
jobs_waiting (threadpool_t * p_threadpool);

static job_t *
get_job (threadpool_t * p_threadpool);

/*** public functions ***/

/**
 * @brief Creates a new threadpool context. initializes the determined amount of
 *        threads and associated signals.
 * 
 * @param thread_count amount of threads that listen for jobs in the threadpool
 * @return threadpool_t*; a new threadpool context.
 * @return NULL; returns NULL on an error
 */
threadpool_t *
threadpool_create (size_t thread_count)
{
    threadpool_t * p_threadpool = calloc(1, sizeof(threadpool_t));
    pthread_t *    p_threads    = calloc(thread_count, sizeof(pthread_t));
    signal_t *     p_signals    = init_signals();

    if ((!p_threadpool) || (!p_threads) || (!p_signals) || (0 == thread_count))
    {
        goto EXIT_ERR;
    }

    p_threadpool->thread_count = thread_count;
    p_threadpool->p_threads    = p_threads;
    p_threadpool->p_jobs_head  = NULL;
    p_threadpool->p_jobs_tail  = NULL;
    p_threadpool->p_signals    = p_signals;

    // initialize threads
    int result = 0;
    for (size_t aix = 0; aix < thread_count; aix++)
    {
        result = pthread_create(&p_threads[aix], NULL, (void *) handle_jobs, p_threadpool);

        // if creating a thread fails, join successfully created threads and error exit
        if (0 != result)
        {
            p_signals->b_run = false;

            for (size_t bix = 0; bix < aix; bix++)
            {
                pthread_join(p_threads[bix], NULL);
            }

            goto EXIT_ERR;
        }

    }

    return p_threadpool;

    EXIT_ERR:
    destroy_signals(&p_signals);
    free(p_threads);
    p_threads = NULL;
    free(p_threadpool);
    p_threadpool = NULL;
    return NULL;
}

/**
 * @brief Adds a new job to the threadpool job queue. If stop signal
 *          received then no jobs will be added to queue.
 * 
 * @param p_threadpool threadpool context to add job to.
 * @param p_job_func function pointer. Signature defined in threadpool.h
 * @param p_data data to be passed to the function. User is responsible for
 *               freeing dynamically allocated memory.
 * @return true successfully added a job
 * @return false no job added to threadpool
 */
bool
threadpool_add_job (threadpool_t * p_threadpool, job_f p_job_func, void * p_data)
{
    job_t * p_job = calloc(1, sizeof(job_t));

    if ((!p_job) || (!p_threadpool) || (!p_job_func) || (!p_threadpool->p_signals->b_run))
    {
        free(p_job);
        p_job = NULL;
        return false;
    }

    p_job->p_job_func = p_job_func;
    p_job->p_data     = p_data;
    p_job->p_next     = NULL;

    pthread_mutex_lock(&p_threadpool->p_signals->mutex);

    if (!p_threadpool->p_jobs_head) // empty queue
    {
        p_threadpool->p_jobs_head = p_job;
    }
    else if (!p_threadpool->p_jobs_tail) // one job in queue
    {
        p_threadpool->p_jobs_head->p_next = p_job;
        p_threadpool->p_jobs_tail = p_job;
    }
    else // multiple jobs in queue
    {
        p_threadpool->p_jobs_tail->p_next = p_job;
        p_threadpool->p_jobs_tail = p_job;
    }

    pthread_cond_signal(&p_threadpool->p_signals->cond);
    pthread_mutex_unlock(&p_threadpool->p_signals->mutex);

    return true;
}

/**
 * @brief Gracefully shutdowns the threadpool. Will complete queued jobs and
 *        then begin the shutdown process. This function frees allocated memory.
 * 
 * @param pp_threadpool pointer to threadpool context to shutdown.
 */
void
threadpool_shutdown (threadpool_t ** pp_threadpool)
{

    if ((!pp_threadpool) || (!*pp_threadpool))
    {
        return;
    }

    (*pp_threadpool)->p_signals->b_run = false;

    pthread_mutex_lock(&(*pp_threadpool)->p_signals->mutex);
    pthread_cond_broadcast(&(*pp_threadpool)->p_signals->cond);
    pthread_mutex_unlock(&(*pp_threadpool)->p_signals->mutex);

    // join threads
    for (size_t idx = 0; idx < (*pp_threadpool)->thread_count; idx++)
    {
        pthread_join((*pp_threadpool)->p_threads[idx], NULL);
    }

    free((*pp_threadpool)->p_threads);
    (*pp_threadpool)->p_threads = NULL;
    destroy_signals(&(*pp_threadpool)->p_signals);

    free(*pp_threadpool);
    *pp_threadpool = NULL;
}

/*** private functions ***/

/**
 * @brief initializes the mutex and conditional for the threadpool.
 *          sets the run flag to true.
 * 
 * @return signal_t* new signal context.
 * @return NULL on error
 */
static signal_t *
init_signals (void)
{
    signal_t * p_signals = calloc(1, sizeof(signal_t));

    if (!p_signals)
    {
        return NULL;
    }

    int mutex_res = pthread_mutex_init(&p_signals->mutex, NULL);
    int cond_res  = pthread_cond_init(&p_signals->cond, NULL);

    p_signals->b_run = true;

    // either a mutex or conditional was unable to be initialized, so destroy them.
    if ((0 != mutex_res) || (0 != cond_res))
    {

        if (0 == mutex_res)
        {
            pthread_mutex_destroy(&p_signals->mutex);
        }

        if (0 == cond_res)
        {
            pthread_cond_destroy(&p_signals->cond);
        }

        free(p_signals);
        p_signals = NULL;
    }

    return p_signals;
}

/**
 * @brief destroys a signal context. Frees associated memory
 * 
 * @param pp_signals pointer to signal context
 */
static void
destroy_signals (signal_t ** pp_signals)
{

    if ((pp_signals) && (*pp_signals))
    {
        pthread_mutex_destroy(&(*pp_signals)->mutex);
        pthread_cond_destroy(&(*pp_signals)->cond);

        free(*pp_signals);
        *pp_signals = NULL;
    }

}

/**
 * @brief puts a thread in a wait status until a job becomes available. Once
 *          a thread gets a job it will execute the function (job_f). Will 
 *          finish up queued jobs when shutdown signal received.
 * 
 * @param p_threadpool 
 * @return void* 
 */
static void *
handle_jobs (threadpool_t * p_threadpool)
{
    job_t * p_curr_job = NULL;

    for (;;)
    {
        pthread_mutex_lock(&p_threadpool->p_signals->mutex);

        // if the job pool is empty, wait. If stop signal recieved or job
        //  available, breakout
        while (p_threadpool->p_signals->b_run && !jobs_waiting(p_threadpool))
        {
            pthread_cond_wait(&p_threadpool->p_signals->cond,
                              &p_threadpool->p_signals->mutex);
        }

        // if stop signal recieved and there are no jobs in job queue, breakout
        if ((!p_threadpool->p_signals->b_run) && !jobs_waiting(p_threadpool))
        {
            pthread_mutex_unlock(&p_threadpool->p_signals->mutex);
            break;
        }

        p_curr_job = get_job(p_threadpool);

        pthread_mutex_unlock(&p_threadpool->p_signals->mutex);

        // calling job function here
        p_curr_job->p_job_func(&p_threadpool->p_signals->b_run,
                               p_curr_job->p_data);

        free(p_curr_job);
        p_curr_job = NULL;
    }

    return NULL;
}

/**
 * @brief determines if there are waiting jobs in the job queue
 * 
 * @param p_threadpool threadpool context
 * @return true jobs are waiting
 * @return false no jobs are waiting
 */
static bool
jobs_waiting (threadpool_t * p_threadpool)
{
    return ((p_threadpool) && (p_threadpool->p_jobs_head));
}

/**
 * @brief Pull the next job in the job queue
 * 
 * @param p_threadpool threadpool context
 * @return job_t* job at the head of the queue
 * @return NULL no job in queue
 */
static job_t *
get_job (threadpool_t * p_threadpool)
{
    job_t * p_job = NULL;
    
    if ((!p_threadpool) || (!p_threadpool->p_jobs_head))
    {
        goto EXIT;
    }

    p_job = p_threadpool->p_jobs_head;

    p_threadpool->p_jobs_head = p_threadpool->p_jobs_head->p_next;

    if (p_threadpool->p_jobs_head == p_threadpool->p_jobs_tail)
    {
        p_threadpool->p_jobs_tail = NULL;
    }

    EXIT:
    return p_job;
}

/*** end of file ***/

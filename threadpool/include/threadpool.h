/**
 * @file threadpool.h
 * @author James M. Horne (jamesmhorne90@gmail.com)
 * @brief A Threadpool data structure. Starts a determined amount of pthreads
 *          that continously wait for a 'job'. A job consists of a function
 *          pointer with a signature defined in threadpool.h. The user is
 *          responsible for how a 'job' behaves; if there is no functionality
 *          within that function to stop execution when the p_b_run flag is
 *          set to false, then the threadpool will not shutdown properly until
 *          the function is complete. The threadpool determines the p_b_run
 *          flag, it is passed when the threadpool calls the function, the
 *          user is only responsible for responding to the flag. The max
 *          threads that can be created is at the cross of max size_t and
 *          what the host machine can handle.
 * @version 0.1
 * @date 2021-12-31
 */

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <stdbool.h>
#include <stdatomic.h>

/**
 * @brief function pointer to a user defined function that can be executed by
 *          a thread in the threadpool. It is up to the user to properly handle
 *          the p_b_run flag so that the threadpool is able to shutdown when
 *          shutdown signal given.
 */
typedef void (*job_f)(_Atomic bool * p_b_run, void * p_data);

typedef struct threadpool_t threadpool_t;

/**
 * @brief Creates a new threadpool context. initializes the determined amount of
 *        threads and associated signals.
 * 
 * @param thread_count amount of threads that listen for jobs in the threadpool
 * @return threadpool_t*; a new threadpool context.
 * @return NULL; returns NULL on an error
 */
threadpool_t *
threadpool_create (size_t thread_count);

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
threadpool_add_job (threadpool_t * p_threadpool, job_f p_job_func, void * p_data);

/**
 * @brief Gracefully shutdowns the threadpool. Will complete queued jobs and
 *        then begin the shutdown process. This function frees allocated memory.
 * 
 * @param pp_threadpool pointer to threadpool context to shutdown.
 */
void
threadpool_shutdown (threadpool_t ** pp_threadpool);

#endif

/*** end of file ***/

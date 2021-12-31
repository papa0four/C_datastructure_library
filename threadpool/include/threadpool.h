/**
 * @file threadpool.h
 * @author James M. Horne (jamesmhorne90@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-31
 */

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <stdbool.h>
#include <stdatomic.h>

typedef void (*job_f)(_Atomic bool * p_b_run, void * p_data);

typedef struct threadpool_t threadpool_t;

threadpool_t *
threadpool_create (size_t thread_count);

bool
threadpool_add_job (threadpool_t * p_threadpool, job_f p_job_func, void * p_data);

void
threadpool_shutdown (threadpool_t ** pp_threadpool);

#endif

/*** end of file ***/

#include <stdio.h>
#include <pthread.h>

// 每个线程拥有独立的副本（C11 线程局部存储）
#define _Thread_local_
#ifdef _Thread_local_
int thread_id = 0; /*普通全局变量*/
#else
_Thread_local int thread_id = 0; /*线程独立局部变量的全部变量*/
#endif

void *worker(void *arg)
{
    thread_id = *(int *)arg; // 设置当前线程的 ID
    printf("thread %d: thread_id = %d\n", thread_id, thread_id);
    return NULL;
}

int main()
{
    int id1 = 1, id2 = 2;
    pthread_t t1, t2;

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 主线程的 thread_id 未修改，仍为 0
    printf("main thread: thread_id = %d\n", thread_id);
    return 0;
}
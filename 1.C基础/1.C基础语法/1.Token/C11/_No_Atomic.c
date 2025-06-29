#include <stdio.h>
#include <pthread.h>

int counter_Atomic = 0; // 普通变量（非原子操作）

void *increment_Atomic(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        counter_Atomic++; // 非原子操作，可能导致数据竞争
    }
    return NULL;
}

int main()
{
    printf("(Expected: 200000)\n");
    for (int i = 0; i < 10; i++)
    {
        pthread_t t1, t2;
        pthread_create(&t1, NULL, increment_Atomic, NULL);
        pthread_create(&t2, NULL, increment_Atomic, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        // 由于数据竞争，结果可能小于 200000
        printf("Counter: %d\n", counter_Atomic);
        counter_Atomic = 0;
    }
    return 0;
}
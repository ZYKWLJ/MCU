#include <pthread.h> // POSIX线程
#include <stdatomic.h>  // 原子操作库
#include <stdio.h>
/**
 * filename:_Atomtic_compare.c
 * description: 测试原子增加
 * author:EthanYankang
 * create time:2025/06/29 13:28:25
 */
_Atomic int counter_Atomic = 0; // 原子整型变量

void *increment_Atomic(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        atomic_fetch_add(&counter_Atomic, 1); // 原子递增
    }
    return NULL;
}

void test_Atomic()
{
    printf("test atomic:\n");
    printf("(Expected: 200000)\n");
    for (int i = 0; i < 10; i++)
    {
        pthread_t t1, t2;
        pthread_create(&t1, NULL, increment_Atomic, NULL);
        pthread_create(&t2, NULL, increment_Atomic, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        printf("Counter: %d\n", atomic_load(&counter_Atomic));

        counter_Atomic = 0;
    }
}

/**
 * filename:_Atomtic_compare.c
 * description: 测试普通增加
 * author:EthanYankang
 * create time:2025/06/29 13:28:25
 */
int counter_normal = 0; // 普通变量（非原子操作）

void *increment_normal(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        counter_normal++; // 非原子操作，可能导致数据竞争
    }
    return NULL;
}
void test_normal()
{
    printf("test normal:\n");
    printf("(Expected: 200000)\n");
    for (int i = 0; i < 10; i++)
    {
        pthread_t t1, t2;
        pthread_create(&t1, NULL, increment_normal, NULL);
        pthread_create(&t2, NULL, increment_normal, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        // 由于数据竞争，结果可能小于 200000
        printf("Counter: %d\n", counter_normal);
        counter_normal = 0;
    }
}
int main()
{
    test_Atomic();
    printf("\n=====================\n");
    test_normal();
    return 0;
}
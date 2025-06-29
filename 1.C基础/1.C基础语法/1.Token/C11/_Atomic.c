#include <pthread.h>    // POSIX线程
#include <stdatomic.h>  // 原子操作库
#include <stdio.h>

atomic_int counter_Atomic = 0;  // 原子整型变量

void* increment_Atomic(void* arg) {
    for (int i = 0; i < 100000; i++) {
        atomic_fetch_add(&counter_Atomic, 1);  // 原子递增
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, increment_Atomic, NULL);
    pthread_create(&t2, NULL, increment_Atomic, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Counter: %d\n", atomic_load(&counter_Atomic));
    return 0;
}
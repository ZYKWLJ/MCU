#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* 全局变量：一个使用volatile修饰，一个不使用 */
volatile int volatileFlag = 0; // 禁止编译器优化
int normalFlag = 0;            // 允许编译器优化

/* 子线程函数：2秒后修改这两个变量的值 */
void *modifierThread(void *arg)
{
    sleep(2);
    printf("Child thread: Setting flags to 1\n");
    volatileFlag = 1;
    normalFlag = 1;
    return NULL;
}

/* 测试volatile变量的行为 */
void testVolatile()
{
    pthread_t tid;
    volatileFlag = 0;
    pthread_create(&tid, NULL, modifierThread, NULL);

    printf("Testing volatile variable...\n");
    while (volatileFlag == 0)
    {
        // 空循环！volatile会强制每次从内存读取
    }
    printf("Volatile test completed!\n");
    pthread_join(tid, NULL);
}

/* 测试普通变量的行为 */
void testNormal()
{
    pthread_t tid;
    normalFlag = 0;
    pthread_create(&tid, NULL, modifierThread, NULL);

    printf("Testing normal variable...\n");
    while (normalFlag == 0)
    {
        // 空循环！编译器可能优化为while(1)
    }
    printf("Normal test completed!\n"); // 可能永远不会执行
    pthread_join(tid, NULL);
}

int main()
{
    testVolatile(); // 先测试volatile变量
    testNormal();   // 再测试普通变量
    return 0;
}

// 注意一定要使用激进的编译优化(O3程度的优化)：
// gcc -O3 -pthread  volatile.c -o volatile.exe
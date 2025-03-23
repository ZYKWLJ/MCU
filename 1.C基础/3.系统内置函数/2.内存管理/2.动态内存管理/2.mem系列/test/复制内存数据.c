#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
    {
        *(arr + i) = i;
        printf("arr[%d]=%d\n", i, *(arr + i));
    }
    int *arr1 = (int *)malloc(10 * sizeof(int));

    // test memcpy
    puts("");
    puts("test memcpy");
    memcpy(arr1, arr + 5, 5 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
    {
        printf("arr1[%d]=%d\n", i, *(arr1 + i));
    }
    // test memcpy for overlap
    // 注意这里可能会出现未定义情况，因为发生了自身重叠赋值！
    puts("");
    puts("test memcpy for overlap");
    memcpy(arr, arr + 5, 5 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
    {
        printf("arr[%d]=%d\n", i, *(arr + i));
    }
    // test memmove
    // 唯一的区别就是memmove可以处理与自身重叠的情况，但是memcpy不可以，所以这个好一点！

    puts("");
    puts("test memmove");
    memmove(arr1, arr + 5, 5 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
    {
        printf("arr[%d]=%d\t", i, *(arr + i));
        printf("arr1[%d]=%d\n", i, *(arr1 + i));

    }
    return 0;
}
/*
结果
arr[0]=0
arr[1]=1
arr[2]=2
arr[3]=3
arr[4]=4
arr[5]=5
arr[6]=6
arr[7]=7
arr[8]=8
arr[9]=9

arr1[0]=5
arr1[1]=6
arr1[2]=7
arr1[3]=8
arr1[4]=9
arr1[5]=0
arr1[6]=0
arr1[7]=0
arr1[8]=0
arr1[9]=0
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int length = 5;
    int arr[length];
    memset(arr, 0, sizeof(arr)); // 初始化为0(单字节填充，多字节必须循环)
    int *arr2 = (int *)malloc(length * sizeof(int));
    int *arr3 = (int *)calloc(sizeof(int),1);
    printf("arr2 = %d\n", *arr2);
    printf("arr3 = %d\n", *arr3);
    // if (arr2 != NULL)
    return 0;
}
#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3;
    int *pointerArray[5] = {&a, &b, &c}; // 指针的数组
    for (int i = 0; i < 3; i++)
    {
        printf("pointerArray[%d]=%p\tvalue=%d\n", i, pointerArray[i], *pointerArray[i]);
    }
    int arr[5] = {1, 2, 3};
    int (*arrayPointer)[5] = &arr; // 数组的指针
    printf("\narr's address=%p\narrayPointer's value=%p", arr, arrayPointer);
    return 0;
}
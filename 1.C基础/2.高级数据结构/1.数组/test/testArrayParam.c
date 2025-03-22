#include <stdio.h>
void sum(int *arr,int length);
void sum2(int arr[],int length);
// 一句话，需要传入数组大小！在传入指针！
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sum(arr,sizeof(arr) / sizeof(arr[0]));//注意这里一定要提前算出数组个数，因为传入的是指针，不能求出大小
    sum2(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}


void sum(int *arr,int length)
{
    int res = 0;
    int i = 0;
    while (i < length)
    {
        res += *arr;
        arr++;
        i++;
        printf("curVal=%d\n", res);
    }
    printf("\nsum=%d\n", res);
}

void sum2(int arr[],int length){//本质还是传入数组
    int res = 0;
    int i = 0;
    while (i < length)
    {
        res += *arr;
        arr++;
        i++;
        printf("curVal=%d\n", res);
    }
    printf("\nsum=%d\n", res);
}
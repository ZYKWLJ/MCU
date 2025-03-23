#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int *p=arr;
    printf("len=%d\n",sizeof(arr)/sizeof(arr[0]));
    return 0;
}
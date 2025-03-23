# include<stdio.h>
# include<string.h>
# include<stdlib.h>
int main(){
    char *arr = (char *)malloc(10 * sizeof(int));
    // 注意这里是设置的每一个字节的内容为a，所以不能使用多字节的变量来设置，否则会出现乱码！
    memset(arr, 'a', 10 * sizeof(int));
    for (int i = 0; i < 10; i++){
        printf("arr[%d]=%c\n", i, *(arr + i));
    }
    return 0;
}

/*
结果
arr[0]=a
arr[1]=a
arr[2]=a
arr[3]=a
arr[4]=a
arr[5]=a
arr[6]=a
arr[7]=a
arr[8]=a
arr[9]=a
 */
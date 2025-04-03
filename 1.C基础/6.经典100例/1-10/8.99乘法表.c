/**
* filename:8.99乘法表.c
* description: 输出99乘法表
* author:EthanYankang
* create time:2025/04/01 21:01:15
*/
#include <stdio.h>
int main(){
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            printf("%d*%d=%d\t", j, i, i*j);
        }
        printf("\n");
    }
return 0;
}
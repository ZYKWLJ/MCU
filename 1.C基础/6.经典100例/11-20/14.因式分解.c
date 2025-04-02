/**
* filename:14.因式分解.c
* description: 题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
* author:EthanYankang
* create time:2025/04/02 18:56:10
*/
// 任何一个数都可以表示为质数235的乘积
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    scanf("%d", &num);
    printf("%d=", num);
    int count2=0,count3=0,count5=0;
    char*str=(char*)malloc(sizeof(char)*100);
    char *ptr=str;
    while(num%2==0){
        num/=2;
        count2++;
        *str='2';
        str++;
    }
    while(num%3==0){
        num/=3;
        count3++;
        *str='3';
        str++;
    }
    while(num%5==0){
        num/=5;
        count5++;
        *str='5';
        str++;
    }
    str=NULL;
    for(int i=0;ptr[i];i++){
        printf("%c",ptr[i]);
        if(ptr[i+1]!='\0')
            printf("*");
    }
    return 0;
}
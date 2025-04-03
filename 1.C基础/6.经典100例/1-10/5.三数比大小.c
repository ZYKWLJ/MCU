/**
 * filename:5.三数比大小.c
 * description:输入三个整数x,y,z，请把这三个数由小到大输出。
 * author:EthanYankang
 * create time:2025/04/01 20:44:32
 */
#include <stdio.h>
void swap(int *a, int *b);
int main()
{
    int a, b, c;
    printf("请输入三个整数：\n");
    scanf("%d%d%d", &a, &b, &c);
    // 强制令a为最大值，b为中间值，c为最小值
    if(a<b){//a一定为最大了
        swap(&a,&b);
        if(a<c){
            swap(&a,&c);
        }
    }
    if(b<c){
        swap(&b,&c);
    }
    printf("从大到小的顺序为：%d %d %d\n", a, b, c);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
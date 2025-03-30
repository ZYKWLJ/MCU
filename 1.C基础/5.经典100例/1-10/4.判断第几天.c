/**
* filename:4.判断第几天.c
* description:
* author:EthanYankang
* create time:2025/03/31 00:26:45
*/
#include <stdio.h>
int main(){
    int year,month,day;
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};//这种做法长见识了！
    printf("请输入年、月、日：");
    scanf("%d %d %d",&year,&month,&day);
    if(year%4==0&&year%100!=0||year%400==0){//覆盖闰年！
        days[1]=29;
    }
    int sum=0;
    for(int i=0;i<month-1;i++){//直接累加判断，剩下最后的day直接加即可！
        sum+=days[i];
    }
    sum+=day;
    printf("%d年%d月%d日是这一年的第%d天\n",year,month,day,sum);
return 0;
}






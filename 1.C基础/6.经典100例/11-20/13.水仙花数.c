/**
* filename:13.水仙花数.c
* description: 大一的时候被折磨，现在吊打ta！
题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。

* author:EthanYankang
* create time:2025/04/02 18:48:34
*/
#include<stdio.h>

int main()
{
	int i,x,y,z;
	for(i=100;i<1000;i++)
	{
		x=i%10;
		y=i/10%10;
		z=i/100%10;
		
		if(i==(x*x*x+y*y*y+z*z*z))
		printf("%d\n",i);
		
	}
	return 0;
}
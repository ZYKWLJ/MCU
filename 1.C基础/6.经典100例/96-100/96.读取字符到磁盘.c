/**
 * filename:96.读取字符到磁盘.c
 * description: 一直从键盘读取输入到磁盘，直至遇到'#'为止
 * author:EthanYankang
 * create time:2025/05/04 23:52:06
 */
#include <stdio.h>
int main()
{
    char ch;
    FILE *fp = fopen("/home/eyk/桌面/MCU/1.C基础/6.经典100例/96-100/txt.txt", "w+");
    while ((ch = (getchar())) != '#')
    {
        fputc(ch, fp);
    }
    printf("写入文件的字符有:\n");
    rewind(fp); // 记得重置文件指针
    while ((ch = fgetc(fp)) != EOF)//p判断是否到达文件末尾
    {
        putchar(ch);
    }
}
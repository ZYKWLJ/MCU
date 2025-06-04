/**
 * filename:97.大小写后写到磁盘.c
 * description: 一直从键盘读取输入到磁盘，将其转化为大写后写到磁盘，直到遇到'!'为止
 * author:EthanYankang
 * create time:2025/05/05 00:04:41
 */

#include <stdio.h>
int main()
{
    char ch;
    FILE *fp = fopen("/home/eyk/桌面/MCU/1.C基础/6.经典100例/96-100/97.txt", "w+");
    while ((ch = getchar()) != '!')
    {
        if (ch >= 'a' && ch <= 'z')
        { // 小写转为大写，其余不变
            ch = ch - 32;
        }
        fputc(ch, fp);
    }
    rewind(fp);
    printf("写入文件的字符有:\n");
    while((ch = fgetc(fp))!= EOF){
        putchar(ch);
    }
}
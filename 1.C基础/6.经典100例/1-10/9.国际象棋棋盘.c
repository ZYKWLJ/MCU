/**
* filename:9.国际象棋棋盘.c
* description:
国际象棋棋盘由64个黑白相间的格子组成，分为8行*8列。用i控制行，
j来控制列，根据i+j的和的变化来控制输出黑方格，还是白方格。
* author:EthanYankang
* create time:2025/04/01 21:03:24
*/
#include<stdio.h>

int main()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if((i+j)%2==0)
                printf("%c%c",219,219);
            else printf("  ");
        printf("\n");
    }
    return 0;
}
/*国际象棋棋盘！
██  ██  ██  ██  
  ██  ██  ██  ██
██  ██  ██  ██  
  ██  ██  ██  ██
██  ██  ██  ██  
  ██  ██  ██  ██
██  ██  ██  ██  
  ██  ██  ██  ██

*/
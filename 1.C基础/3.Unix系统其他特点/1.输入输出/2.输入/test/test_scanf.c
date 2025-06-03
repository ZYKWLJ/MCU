#include <stdio.h>
#include<stdlib.h>
int main(){
    int a;
    printf("test scanf\n");
    scanf("%d",&a);
    printf("%d\n",a);
    // char* str;但由于 str 未初始化，它指向的是一个随机的内存地址，这会导致未定义行为，可能会使程序崩溃。
    // 为 str 分配内存
    char* str = (char*)malloc(100 * sizeof(char));
    scanf("%s",str);//限定了读取个数为1个！
    printf("%s\n",str);


    printf("\ntest sscanf\n");
    char*s1="hello";
    char *s2=malloc(sizeof(char)*10);
    sscanf(s1,"%s",&s2);
    printf("The str read is %c\n",s2);
    char s3;
    sscanf(s1,"%c",&s3);
    printf("The char read is %c\n",s3);

    printf("\ntest fscanf\n");
    FILE*fp=fopen("fscanf.txt","r");//打开文件
    if (fp)
    {
          char *str=(char*)malloc(100*sizeof(char));
          fscanf(fp,"%s",str);//遇到空格、换行符、制表符等停止！
          printf("%s\n",str);
          fclose(fp);
          free(str);  
    }

    return 0;
}
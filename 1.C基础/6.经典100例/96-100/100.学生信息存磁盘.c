#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char *string;
typedef struct stu_
{
    int id;
    string name;
    float score[3];
    float avg;
} *stu;

// 生成 60 到 100 之间的随机数
int get_score()
{
    return 60 + rand() % (100 - 60 + 1);
}

int main()
{
    stu s[5];
    // 设置随机数种子，只调用一次
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        s[i] = (stu)malloc(sizeof(struct stu_));
        if (s[i] == NULL)
        {
            fprintf(stderr, "内存分配失败\n");
            return 1;
        }

        s[i]->id = get_score();

        s[i]->name = (string)malloc(100 * sizeof(char));
        if (s[i]->name == NULL)
        {
            fprintf(stderr, "内存分配失败\n");
            free(s[i]);
            return 1;
        }
        sprintf(s[i]->name, "stu_%d", i);

        s[i]->avg = 0;
        for (int j = 0; j < 3; j++)
        {
            s[i]->score[j] = (float)get_score();
            s[i]->avg += s[i]->score[j];
        }
        s[i]->avg /= 3;
    }

    FILE *fp = fopen("/home/eyk/桌面/MCU/1.C基础/6.经典100例/96-100/100.txt", "w+");
    if (fp == NULL)
    {
        fprintf(stderr, "文件打开失败\n");
        // 释放之前分配的内存
        for (int i = 0; i < 5; i++)
        {
            free(s[i]->name);
            free(s[i]);
        }
        return 1;
    }

    fprintf(fp, "%-20s%-20s%-20s%-20s%-20s%-20s\n", "std_id", "std_name", "lesson1", "lesson2", "lesson3", "average");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fp, "%-20d%-20s%-20.2f%-20.2f%-20.2f%-20.2f\n", s[i]->id, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], s[i]->avg);
    }

    fclose(fp);

    // 释放分配的内存
    for (int i = 0; i < 5; i++)
    {
        free(s[i]->name);
        free(s[i]);
    }

    return 0;
}
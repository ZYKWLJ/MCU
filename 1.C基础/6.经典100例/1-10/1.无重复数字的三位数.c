/**
* filename:1.无重复数字的三位数1.c
* description:
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
分析：使用回溯法来完成的！
* author:EthanYankang
* create time:2025/03/29 21:02:20

*/
#include <stdio.h>

void dfs(int startIndex, int *nums, int numsSize, int *used, int *path, int pathTop, int ans[][3], int ansTop)
{
    if (pathTop == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%d", path[i]);
        }
        printf("\n");
        return;
        for (int i = 0; i < 3; i++)
        {
            ans[ansTop][i] = path[i];
        }
        ansTop++;
        return;
    }
    for (int i = 0; i < 5; i++)
    { // 遍历nums数组！
        if (used[i] == 1)
            continue;
        used[i] = 1;
        path[pathTop++] = nums[i]; // 这里模拟栈的核心！使用pathTop来模拟栈顶的指针！
        dfs(0, nums, numsSize, used, path, pathTop, ans, ansTop);
        pathTop--;
        used[i] = 0;
    }
}
int main()
{
    int ans[][3] = {0};
    int used[4] = {0};
    int path[3] = {0};
    int pathTop = 0;
    int nums[] = {1, 2, 3, 4};
    int ansTop = 0;
    dfs(0, nums, 4, used, path, pathTop, ans, ansTop);
    return 0;
}
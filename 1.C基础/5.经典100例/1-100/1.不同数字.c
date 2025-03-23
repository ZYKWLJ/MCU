#include <stdio.h>

int path[3];
int pathTop = 0;

// 深度优先搜索函数
void dfs(int *nums, int arrLength, int *used) {
    if (pathTop == 3) {
        for (int i = 0; i < sizeof(path) / sizeof(path[0]); i++) {
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < arrLength; i++) {
        if (used[i] == 1)
            continue;
        used[i] = 1;
        path[pathTop++] = nums[i];
        dfs(nums, arrLength, used);
        pathTop--;
        used[i] = 0;
    }
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int used[4] = {0}; 
    dfs(nums, sizeof(nums) / sizeof(nums[0]), used);
    return 0;
}    
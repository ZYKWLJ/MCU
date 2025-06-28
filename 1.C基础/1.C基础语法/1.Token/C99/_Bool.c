#include <stdio.h>

int main(void)
{
    _Bool is_valid = 1; // 明确逻辑“真”，可读性优于 int is_valid = 1;
    if (is_valid)
    {
        // 执行逻辑
        printf("Hello");
    }
    return 0;
}


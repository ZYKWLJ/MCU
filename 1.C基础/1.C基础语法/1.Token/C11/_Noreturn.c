#include <stdio.h>
#include <stdlib.h>

// 标记函数不会返回（如终止程序或进入无限循环）
// 使用_Noreturn让程序语义更好！
_Noreturn void fatal_error(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

int main() {
    if (1) {  // 模拟错误条件
        fatal_error("No memory\n");  // 调用后不会返回，编译器可优化
    }
    // 以下代码永远不会执行，编译器可能警告或优化掉
    printf("continue execute...\n");
    return 0;
}
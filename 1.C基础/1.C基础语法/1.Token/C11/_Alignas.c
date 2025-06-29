#include <stdio.h>

// 正确语法：_Alignas 直接修饰结构体，括号紧跟关键字
struct Vector {
    float x, y, z, w;
} __attribute__((aligned(16)));  // GCC/Clang 扩展写法（兼容更多场景）
// 或标准 C11 写法（部分编译器需调整）：
// struct Vector _Alignas(16) { float x, y, z, w; }; 

int main() {
    // 查询对齐值（C11 标准用法）
    printf("Vector aligned: %zu byte\n", _Alignof(struct Vector));
    // 输出 16（因 4 个 float 共 16 字节，且对齐到 16 字节）
    printf("Vector size: %zu byte\n", sizeof(struct Vector)); 
    return 0;
}


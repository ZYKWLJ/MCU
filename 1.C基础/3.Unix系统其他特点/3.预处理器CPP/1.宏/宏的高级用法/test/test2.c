/**
* filename:test2.c
* description:
* author:EthanYankang
* create time:2025/04/01 10:15:38
*/
#include <stdio.h>
#define PRINT(x) printf(#x " = %d\n", x)
int main() {
    int a = 10;
    PRINT(a); // 输出 "a = 10"
    return 0;
}
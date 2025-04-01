/**
* filename:test3.c
* description:生成统一前后缀名称的功能！
* author:EthanYankang
* create time:2025/04/01 10:17:04
*/
#include <stdio.h>
#define UNIFORM_FUNC(name) (FUNC_##name)
void UNIFORM_FUNC(hello)(){
    
    printf("this is hello func\n");
}

void UNIFORM_FUNC(world)(){
    printf("this is world func\n");
}
int main(){
    UNIFORM_FUNC(hello)();//展开为FUNC_hello()
    UNIFORM_FUNC(world)();//展开为FUNC_world()
}
# 一、#include的本质
多文件编译，准确来说是`多个.c文件`**(.h可加可不加**)**编译

# 二、多文件编译实战

## (一)多文件源码及组织形式
### my.h
```c
#ifndef
# define _MY_
#include<stdio.h> //实际上的开发都是在头文件里面写声明及引入，在.c文件里面写函数定义
int test();
#endif
```

### my.c
```c
# include "my.h"//这里只写函数定义！只引入对应.h一个文件即可！
void test(){
    puts("test");
}
```

### main.c
```c
#include <stdio.h>
#include "my.h"
int main(){
    test();
    return 0;
}
```

## (二)编译
```shell
gcc main.c my.c -o main
```
这里`加不加.h都可以`！但是`必须加上.c文件`！类似于`接口与实现`！

## (三)查看.i文件，探寻本质——代码插入
```shell
gcc -E main.c -o main.i
```
这是预处理后的.i文件本质，无非就是`插入#include引入的代码！`
```
# 2 "main.c" 2
# 1 "my.h" 1





# 5 "my.h"
void test();
# 3 "main.c" 2
int main(){
    test();
    return 0;
}
```

# 一、定义
宏即define，本质是`文本替换`！

# 二、函数定义
详情：
```c
# define ONE 1
# define ADD(a,b) a+b
#include <stdio.h>
int main(){
    int a = 100;
    printf("%d\n%d\n",ONE,ADD(a,ONE));
    return 0;
}
```

# 三、换行
注意宏的换行！这是编译器的识别特点哦~
```c
# define ONE 1
# define ADD(a,b) a \
+b
#include <stdio.h>
int main(){
    int a = 100;
    printf("%d\n%d\n",ONE,ADD(a,ONE));
    return 0;
}

```
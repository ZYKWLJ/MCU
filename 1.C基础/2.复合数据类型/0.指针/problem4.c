#include <stdio.h>
#include <stdlib.h>
int *return_pointer(void)
{
    int a = 5;
    printf("in valid field:%d\n", a);
    return &a;
}
int main(void)
{
    /**
     * data descp: 解控引用指针
     */
#if 0
    /**
     * data descp: 空引用形式1——未初始化，解引用报错。此种最严重，不能出现这样的情况！
     */
    int *p;
    /**
     * data descp: 空引用形式2——初始化为NULL，解引用报错！
     */
    int *p = NULL;
    printf("%d\n", *p);
#endif
    /**
     * data descp: 内存泄漏
     */
#if 0
    int *p=(int *)malloc(sizeof(int)*100);
    for(int i=0;i<100;i++){
        p[i]=i;
    }
    // 如果不调用free()释放，进程运行期间，内存会一直被占用，直到进程结束！
    // free(p);
#endif
    /**
     * data descp: 悬挂指针
     */
#if 0
    int *p = return_pointer();
    /**
    * data descp: 这里的p是一个悬挂指针，指向的内存已经被释放了！解空引用，报错！
    */
    printf("out valid field:%d\n", *p);
#endif
#if 1
    int *p = (int *)malloc(sizeof(int) * 100);
    free(p);
    printf("first time free succeed!\n");
    free(p);
    printf("second time free succeed!\n");
#endif
    return 0;
}
#include "seqlist.h"

// 定义栈结构体
typedef struct Stack
{
    int top;       // 定义栈顶指针
    SeqList *list; // 底层实现
} Stack;

// 初始化栈
Stack *_init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    //	调用顺序表的初始化函数
    stack->list = _init_seqlist();
    stack->top = 0;
    return stack;
}

// 压入元素
int _push(Stack *stack, int element)
{
    assert(stack != NULL); // 断言编译阶段调试
    if (_insert(stack->list, stack->list->size, element) == 0)
    {
        printf("分配内存失败，退出程序");
    }
    stack->top++;
    return 1;
}

int empty(Stack *stack)
{
    return stack->list->size > 0;
}

// 删除元素
int _pop(Stack *stack)
{
    if (empty(stack) == 0)
    {
        printf("弹出元素失败，栈已为空\n");
        return 0;
    }
    if (_delete(stack->list, stack->list->size - 1) == 1)
    {
        return 0;
    }
    stack->top--;
    return 1;
}

// 按值查找元素，返回其在顺序表中的位置（从0开始，存在多个返回第一个），若不存在返回 -1
int _find_stack(Stack *stack, int element)
{
    return _find(stack->list, element);
}

// 按位置获取元素值
int _get_stack(Stack *stack, int position)
{
    return _get(stack->list, position);
}

// 打印栈中的所有元素
void _print_stack(Stack *stack)
{
    _print(stack->list);
}

// 销毁栈，释放内存
void _destroy_stack(Stack *stack)
{
    free(stack->list);
    free(stack);
}

int main()
{
    puts("初始化栈:");
    Stack *stack = _init_stack();
    puts("\n测试压入功能:");
    puts("\n往栈中压入5个元素:");
    for (int i = 0; i < 5; i++)
    {
        _push(stack, i);
        _print_stack(stack);
    }

    puts("\n测试查找指定位置的元素值:");
    _print_stack(stack);
    for (int i = 0; i < 5; i++)
    {
        printf("指定位置%d的元素值为:%d\n", i, _get_stack(stack, i));
    }

    puts("\n测试查找指定值元素位置:");
    _print_stack(stack);
    for (int i = 0; i < 5; i++)
    {
        printf("指定值%d的元素位置为:%d\n", i, _find_stack(stack, i));
    }

    puts("\n测试弹出功能:");
    for (int i = 5; i < 12; i++)
    {
        printf("弹出第%d次\n", i);
        _pop(stack);
        _print_stack(stack);
    }
    _print_stack(stack);
    return 0;
}
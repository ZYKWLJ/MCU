#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_CAPACITY 10 // 默认初始容量

// 定义顺序表结构体
typedef struct SeqList
{
    int *data;    // 用于存储数据元素的数组指针，即保存表中存储元素的首地址
    int size;     // 当前顺序表中元素的个数
    int capacity; // 顺序表的容量（即能存储的最大元素个数）
} SeqList;

// 初始化顺序表
SeqList *_init()
{
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    if (list == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    list->data = (int *)malloc(DEFAULT_CAPACITY * sizeof(int));
    if (list->data == NULL)
    {
        printf("数据区内存分配失败！\n");
        free(list);
        return NULL;
    }
    list->size = 0;
    list->capacity = DEFAULT_CAPACITY;
    return list;
}

// 在指定位置插入元素(默认向前插入)
int _insert(SeqList *list, int position, int element)
{
    assert(list != NULL); // 断言编译阶段调试
    if (position < 0 || position > list->size)
    {
        printf("插入位置%d非法！只能在[%d,%d]内插入\n", position, 0, list->size); // 注意可以在后面插入!
        return 0;
    }
    // 检查是否需要扩容
    if (list->size >= list->capacity)
    { // 懒检查，只有在插入时才检查扩容
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
        if (list->data == NULL)
        {
            printf("扩容时内存分配失败！\n");
            exit(EXIT_FAILURE);
        }
    }
    //  插入点的所有元素后移
    for (int i = list->size; i > position; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    //  插入点位置元素更新
    list->data[position] = element;
    list->size++; // 存放元素大小+1
    return 1;     // 插入成功！
}

// 删除指定位置的元素
int _delete(SeqList *list, int position)
{
    assert(list != NULL);
    if (position < 0 || position >= list->size)
    {
        printf("删除位置%d非法！只能在[%d,%d]内删除\n", position, 0, list->size - 1);
        return 0;
    }
    for (int i = position; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    return 1;
}

// 将指定位置的值改为指定值
int _set(SeqList *list, int position, int val)
{
    assert(list != NULL);
    if (position < 0 || position >= list->size)
    {
        printf("位置%d非法！位置范围为[%d,%d]\n", position, 0, list->size - 1);
        return 0;
    }
    list->data[position] = val;
    return 1;
}

// 按值查找元素，返回其在顺序表中的位置（从0开始，存在多个返回第一个），若不存在返回 -1
int _find(SeqList *list, int element)
{
    assert(list != NULL);
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// 按位置获取元素值
int _get(SeqList *list, int position)
{
    assert(list != NULL);
    if (position < 0 || position >= list->size)
    {
        printf("查找位置%d非法！只能在[%d,%d]内查找\n", position, 0, list->size - 1);
        return -1;
    }
    return list->data[position];
}

// 打印顺序表中的所有元素
void _print(SeqList *list)
{
    assert(list != NULL);
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 销毁顺序表，释放内存
void _destroy(SeqList *list)
{
    assert(list != NULL);
    free(list->data);
    free(list);
}

int main()
{
    puts("初始化顺序表:");
    SeqList *SeqList = _init();
    puts("\n测试插入功能:");
    puts("\n测试往末尾插入5个元素:");
    for (int i = 0; i < 5; i++)
    {
        _insert(SeqList, SeqList->size, i);
        _print(SeqList);
    }
    puts("\n测试往头部尾插入5个元素:");
    for (int i = 5; i < 10; i++)
    {
        _insert(SeqList, 0, i);
        _print(SeqList);
    }
    puts("\n测试删除指定位置元素:");
    for (int i = 5; i < 10; i++)
    {
        printf("删除位置%d处的元素:\n", i);
        _delete(SeqList, i);
        _print(SeqList);
    }

    puts("\n测试查找指定位置的元素值:");
    _print(SeqList);
    for (int i = 0; i < 5; i++)
    {
        printf("指定位置%d的元素值为:%d\n", i, _get(SeqList, i));
    }

    puts("\n测试查找指定值元素位置:");
    _print(SeqList);
    for (int i = 0; i < 5; i++)
    {
        printf("指定值%d的元素位置为:%d\n", i, _find(SeqList, i));
    }

    puts("\n测试将指定位置的值改为指定值:");
    _print(SeqList);
    for (int i = 0; i < 5; i++)
    {
        int origin = _get(SeqList, i);
        put(SeqList, i, i + 10);
        printf("指定位置%d的元素原本为%d,更改后为:%d\n", i, origin, _get(SeqList, i));
    }
    _print(SeqList);
    return 0;
}
#include "seqlist.h"
typedef struct Queue
{
    SeqList *list; // 底层实现
} Queue;

// 初始化队列
Queue *_init_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue) * 1);
    if (queue == NULL)
    {
        perror("内存分配失败!\n");
        return NULL;
    }
    //	为顺序表分配内存
    queue->list = _init_seqlist();
    return queue;
}
// 队尾==========队首

// 队首压入数据
int push_front(Queue *queue, int element)
{
    return _insert(queue->list, queue->list->size, element);
}

// 队尾压入数据
int push_back(Queue *queue, int element)
{
    return _insert(queue->list, 0, element);
}

// 队首弹出数据
int pop_front(Queue *queue)
{
    return _delete(queue->list, queue->list->size - 1);
}

// 队尾弹出数据
int pop_back(Queue *queue)
{
    return _delete(queue->list, 0);
}

void print_queue(Queue *queue)
{
    _print(queue->list);
}

void _destory_queue(Queue *queue)
{
    _destroy_seqlist(queue->list);
    free(queue);
}
int main()
{
    puts("1、初始化队列:");
    Queue *queue = _init_queue();
    puts("\n2、测试压入数据功能:");
    puts("\n2.1、往队首压入5个元素:");
    for (int i = 0; i < 5; i++)
    {
        push_front(queue, i);
        print_queue(queue);
    }

    puts("\n2.2、往队尾压入5个元素:");
    for (int i = 5; i < 10; i++)
    {
        push_back(queue, i);
        print_queue(queue);
    }

    puts("\n3、测试弹出数据功能:");
    puts("\n3.1、往队首弹出3个元素:");
    for (int i = 0; i < 5; i++)
    {
        pop_front(queue);
        print_queue(queue);
    }

    puts("\n3.2、往队尾弹出3个元素:");
    for (int i = 0; i < 3; i++)
    {
        pop_back(queue);
        print_queue(queue);
    }
    puts("\n4、销毁队列\n");
    _destory_queue(queue);
    puts("\n5、测试完毕!");
    return 0;
}
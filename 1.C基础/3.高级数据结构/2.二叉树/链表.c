#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    struct ListNode *next;
    int val;
};

struct ListNode *build()
{
    int val;
    struct ListNode *curNode = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    printf("请输入节点值:");
    if (scanf("%d", &val) != 1)
    {
        printf("结束输入！");
        return NULL; // 返回NULL作为后续节点
    }
    curNode->val = val;
    curNode->next = build();
}

void print(struct ListNode *head)
{
    while (head)
    {
        printf("节点%d", head->val);
        if (head->next)
        {
            printf("-->");
        }
        head = head->next;
    }
}

int main()
{
    printf("构造节点：\n");
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    head->val = 1;
    head->next = build();
    printf("打印节点：\n");
    print(head->next);
    return 0;
}
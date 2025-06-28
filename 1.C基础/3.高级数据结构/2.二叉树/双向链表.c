#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    struct ListNode *pre;
    struct ListNode *next;
    int val;
};

struct ListNode *build(struct ListNode *pre)
{
    int val;
    struct ListNode *curNode = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    printf("请输入节点值:");
    while (scanf("%d", &val) != 1)
    {
        printf("输入结束");
        return NULL;
    }
    curNode->val = val;
    curNode->pre = pre;
    curNode->next = build(curNode);
}

void print(struct ListNode *head)
{
    while (head->next)
    {
        printf("节点%d(%p)", head->val, head);
        printf("-->");
        head = head->next;
    }
    printf("节点%d(%p)", head->val, head);

    puts("\n反向打印:");
    while (head->pre)
    {
        printf("节点%d(%p)", head->val, head);
        printf("-->");
        head = head->pre;
    }
    printf("节点%d(%p)", head->val, head);
}

int main()
{
    printf("构造节点：\n");
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    head->val = 0;
    head->pre = NULL;
    head->next = build(head);
    printf("打印节点：\n");
    print(head);
    return 0;
}
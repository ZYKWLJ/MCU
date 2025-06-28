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
    printf("������ڵ�ֵ:");
    while (scanf("%d", &val) != 1)
    {
        printf("�������");
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
        printf("�ڵ�%d(%p)", head->val, head);
        printf("-->");
        head = head->next;
    }
    printf("�ڵ�%d(%p)", head->val, head);

    puts("\n�����ӡ:");
    while (head->pre)
    {
        printf("�ڵ�%d(%p)", head->val, head);
        printf("-->");
        head = head->pre;
    }
    printf("�ڵ�%d(%p)", head->val, head);
}

int main()
{
    printf("����ڵ㣺\n");
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    head->val = 0;
    head->pre = NULL;
    head->next = build(head);
    printf("��ӡ�ڵ㣺\n");
    print(head);
    return 0;
}
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
    printf("������ڵ�ֵ:");
    if (scanf("%d", &val) != 1)
    {
        printf("�������룡");
        return NULL; // ����NULL��Ϊ�����ڵ�
    }
    curNode->val = val;
    curNode->next = build();
}

void print(struct ListNode *head)
{
    while (head)
    {
        printf("�ڵ�%d", head->val);
        if (head->next)
        {
            printf("-->");
        }
        head = head->next;
    }
}

int main()
{
    printf("����ڵ㣺\n");
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    head->val = 1;
    head->next = build();
    printf("��ӡ�ڵ㣺\n");
    print(head->next);
    return 0;
}
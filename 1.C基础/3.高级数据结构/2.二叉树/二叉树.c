/**
 * filename:������.c
 * description: ��������ʵ��
 * author:EthanYankang
 * create time:2025/04/03 13:00:00
 */
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// ����������
TreeNode *buildTree()
{
    int val;
    // ��ȡ����ֵ������������Ƿ���Ч
    if (scanf("%d", &val) != 1)
    {
        printf("Invalid input. Please enter an integer.\n");
        return NULL;
    }
    if (val == -1)
    {
        return NULL;
    }
    // Ϊ�½ڵ�����ڴ�
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->val = val;
    // �ݹ鹹����������������
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

// ��ӡ��������ǰ�������
void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

// �ͷŶ�����ռ�õ��ڴ�
void freeTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // �ݹ��ͷ���������������
    freeTree(root->left);
    freeTree(root->right);
    // �ͷŵ�ǰ�ڵ�
    free(root);
}

int main()
{
    printf("Please enter the node values of the binary tree, separated by spaces, and enter -1 to indicate that the node is empty.\n");
    // ����������
    TreeNode *root = buildTree();
    // ��ӡ��������ǰ����������
    printf("The preorder traversal of the binary tree results in:\n");
    printTree(root);
    printf("\n");
    // �ͷŶ�����ռ�õ��ڴ�
    freeTree(root);
    return 0;
}
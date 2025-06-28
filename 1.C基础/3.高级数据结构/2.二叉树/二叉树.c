/**
 * filename:二叉树.c
 * description: 二叉树的实现
 * author:EthanYankang
 * create time:2025/04/03 13:00:00
 */
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 构建二叉树
TreeNode *buildTree()
{
    int val;
    // 读取输入值，并检查输入是否有效
    if (scanf("%d", &val) != 1)
    {
        printf("Invalid input. Please enter an integer.\n");
        return NULL;
    }
    if (val == -1)
    {
        return NULL;
    }
    // 为新节点分配内存
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->val = val;
    // 递归构建左子树和右子树
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

// 打印二叉树（前序遍历）
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

// 释放二叉树占用的内存
void freeTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // 递归释放左子树和右子树
    freeTree(root->left);
    freeTree(root->right);
    // 释放当前节点
    free(root);
}

int main()
{
    printf("Please enter the node values of the binary tree, separated by spaces, and enter -1 to indicate that the node is empty.\n");
    // 构建二叉树
    TreeNode *root = buildTree();
    // 打印二叉树（前序遍历结果）
    printf("The preorder traversal of the binary tree results in:\n");
    printTree(root);
    printf("\n");
    // 释放二叉树占用的内存
    freeTree(root);
    return 0;
}
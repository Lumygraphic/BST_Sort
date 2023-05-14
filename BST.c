#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    int data;                // 数据域
    struct BiTNode* lchild;  // 左孩子
    struct BiTNode* rchild;  // 右孩子
    int cunt_emergy;         // 记录重复数据
} BiTNode, * BiTree;

BiTNode* BST_insert1(BiTNode* T, int k)  // 插入节点方法一（返回值为指针）
{
    if (T == NULL) { //初始化二叉树
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
        T->cunt_emergy = 0;
        return T;
    }
    else if (T->data == k)  // BST不能插入相同数据域结点（但可以改造一下进行排序）
    {
        T->cunt_emergy += 1;//重复则计数加一
        return T;
        //return NULL;
    }
    else if (T->data > k) {
        T->lchild = BST_insert1(T->lchild, k);
        return T;
    }
    else {
        T->rchild = BST_insert1(T->rchild, k);
        return T;
    }
}

void BST_insert2(BiTNode** T, int k)  // 插入节点方法2（返回值为空）
{
    if (*T == NULL) { //初始化二叉树
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = k;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->cunt_emergy = 0;
    }
    else if ((*T)->data == k)  // BST不能插入相同数据域结点（但可以改造一下进行排序）
    {
        (*T)->cunt_emergy += 1;//重复则计数加一
        return;
    }
    else if ((*T)->data > k)
        BST_insert2(&((*T)->lchild), k);
    else
        BST_insert2(&((*T)->rchild), k);
}

void Print_BiTree_InOrder(BiTNode* T)  // 中序遍历二叉树
{
    if (T) {
        Print_BiTree_InOrder(T->lchild);
        //printf("%d ", T->data);
        while (T->cunt_emergy >= 0) //有重复结点则循环输出
        {
            printf("%d ", T->data);
            T->cunt_emergy--;
        }
        Print_BiTree_InOrder(T->rchild);
    }
}

int main() {
    BiTree T1 = NULL, T2 = NULL;  // 初始化二叉树
    int n, bot;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &bot);
        //printf("%d\n", bot);
        T1 = BST_insert1(T1, bot);
        BST_insert2(&T2, bot);
    }
    if (T1 == NULL)
        printf("NULL\n");
    printf("第一种BST排序方法:\n");
    Print_BiTree_InOrder(T1);
    printf("\n");
    printf("第二种BST排序方法:\n");
    Print_BiTree_InOrder(T2);
    printf("\n");
    return 0;
}
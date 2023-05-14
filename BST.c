#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    int data;                // ������
    struct BiTNode* lchild;  // ����
    struct BiTNode* rchild;  // �Һ���
    int cunt_emergy;         // ��¼�ظ�����
} BiTNode, * BiTree;

BiTNode* BST_insert1(BiTNode* T, int k)  // ����ڵ㷽��һ������ֵΪָ�룩
{
    if (T == NULL) { //��ʼ��������
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
        T->cunt_emergy = 0;
        return T;
    }
    else if (T->data == k)  // BST���ܲ�����ͬ�������㣨�����Ը���һ�½�������
    {
        T->cunt_emergy += 1;//�ظ��������һ
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

void BST_insert2(BiTNode** T, int k)  // ����ڵ㷽��2������ֵΪ�գ�
{
    if (*T == NULL) { //��ʼ��������
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = k;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->cunt_emergy = 0;
    }
    else if ((*T)->data == k)  // BST���ܲ�����ͬ�������㣨�����Ը���һ�½�������
    {
        (*T)->cunt_emergy += 1;//�ظ��������һ
        return;
    }
    else if ((*T)->data > k)
        BST_insert2(&((*T)->lchild), k);
    else
        BST_insert2(&((*T)->rchild), k);
}

void Print_BiTree_InOrder(BiTNode* T)  // �������������
{
    if (T) {
        Print_BiTree_InOrder(T->lchild);
        //printf("%d ", T->data);
        while (T->cunt_emergy >= 0) //���ظ������ѭ�����
        {
            printf("%d ", T->data);
            T->cunt_emergy--;
        }
        Print_BiTree_InOrder(T->rchild);
    }
}

int main() {
    BiTree T1 = NULL, T2 = NULL;  // ��ʼ��������
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
    printf("��һ��BST���򷽷�:\n");
    Print_BiTree_InOrder(T1);
    printf("\n");
    printf("�ڶ���BST���򷽷�:\n");
    Print_BiTree_InOrder(T2);
    printf("\n");
    return 0;
}
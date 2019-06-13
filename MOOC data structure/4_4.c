#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
Position Find(BinTree BST, ElementType X)
{ //写成循环
    while (BST != NULL)
    {
        if (BST->Data == X)
            return BST;
        else if (BST->Data > X)
            BST = BST->Left;
        else
            BST = BST->Right;
    }
    //printf("Not Found\n");
    return NULL;
}
Position FindMin(BinTree BST)
{ //循环
	if (!BST)return NULL;
    while (BST->Left != NULL)
        BST = BST->Left;
    return BST;
}
Position FindMax(BinTree BST)
{ //递归
	if (BST == NULL||BST->Right == NULL )
        return BST;
    else
        FindMax(BST->Right);
}
BinTree Insert(BinTree BST, ElementType X)
{
    if (BST == NULL)
    { //若空树，生成并返回一个结点的二叉搜索树
        BST = malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
        return BST;
    }
    else if (BST->Data > X)
        BST->Left = Insert(BST->Left, X);
    else if (BST->Data < X)
        BST->Right = Insert(BST->Right, X);
    return BST;
}
BinTree Delete(BinTree BST, ElementType X)
{
	if (BST == NULL)
        printf("Not Found\n");
    else if (BST->Data > X)
        BST->Left = Delete(BST->Left, X);
    else if (BST->Data < X)
        BST->Right = Delete(BST->Right, X);
    else
    { //找到值，分三种情况
        if (!BST->Left && !BST->Right)
        { //该结点为叶结点
            free(BST);
            return NULL;
        }
        else if (BST->Left && BST->Right)
        { //该结点有左右子树,用右子树的最小元素或者左子树的最大元素替代
			BinTree Parent = BST;
			BinTree	Child = Parent->Right;
			while (Child->Left){
				Parent = Child;
				Child = Child->Left;
			}
            int ReplaceData = Child->Data;
            if(Parent!=BST)Parent->Left= Delete(Child, ReplaceData);
			else Parent->Right = Delete(Child, ReplaceData);
            BST->Data = ReplaceData;
        }
        else
        { //该结点只有一支子树
            BinTree q;
            if (BST->Left)
                q = BST->Left;
            else
                q = BST->Right;
            free(BST);
            return q;
        }
    }
    return BST;
}
void PreorderTraversal(BinTree BT){
    if(BT){
        printf("%d ",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal(BinTree BT){
    if (BT){
		InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
		InorderTraversal(BT->Right);
    }
}


int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
	MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL)
            printf("%d is not found\n", X);
        else
        {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP)
                printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP)
                printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");
	system("pause");
    return 0;
}
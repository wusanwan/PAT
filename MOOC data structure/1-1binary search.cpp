#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	L = new LNode;
	ElementType X;
	Position P;
	int n;
	scanf("%d", &n);
	L->Last = n;
	for (int i = 1; i <= n; i++){
		scanf("%d", &L->Data[i]);
	}
	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	system("pause");
	return 0;
}
Position BinarySearch(List L, ElementType X){
	Position left=1, right=L->Last,mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (L->Data[mid] == X)return mid;
 		else if (L->Data[mid]<X){
			left = mid+1 ;
		}
		else right = mid-1;
	}
	return NotFound;
}
/* 你的代码将被嵌在这里 */
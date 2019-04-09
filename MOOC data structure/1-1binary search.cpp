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
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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
/* ��Ĵ��뽫��Ƕ������ */
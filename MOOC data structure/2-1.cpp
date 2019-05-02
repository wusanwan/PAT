#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	List   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	system("pause");
	return 0;
}
#include <malloc.h>
List Merge(List L1, List L2){			//注意此时 L1和L2是值传递，L1,L2的值是不变的（但是L1和L2的next是通过指针改的，画张图就很明白了
	List L = (struct Node*)malloc(sizeof(struct Node));					//不加struct会报错……编译器是C的原因吗……
	List mark = L;
	List a = L1->Next;
	List b = L2->Next;

	while (a != NULL && b!= NULL){
		if (a->Data <= b->Data){
			mark ->Next = a;
			a = a->Next;
			mark = mark ->Next;
		}
		else{
			mark->Next = b;
			b = b->Next;
			mark = mark->Next;
		}
	}
	if (a != NULL){
		mark->Next = a;
	}
	if (b != NULL){
		mark->Next = b;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}

List Read(){
	List a=(List)malloc(sizeof(Node)); 
	List rear = a;
	a->Next = NULL;
	int n,t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		List temp = (List)malloc(sizeof(Node));
		scanf("%d", &t);
		temp->Data = t;
		temp->Next = NULL;
		rear->Next = temp;
		rear = rear->Next;
	}
	return a;
} 
void Print(List L){ 
	if (L->Next == NULL){
		printf("NULL ");
	}
	while (L->Next != NULL){
		L = L->Next;
		printf("%d ", L->Data);
	}
	printf("\n");
} 

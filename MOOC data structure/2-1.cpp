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

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

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
List Merge(List L1, List L2){			//ע���ʱ L1��L2��ֵ���ݣ�L1,L2��ֵ�ǲ���ģ�����L1��L2��next��ͨ��ָ��ĵģ�����ͼ�ͺ�������
	List L = (struct Node*)malloc(sizeof(struct Node));					//����struct�ᱨ������������C��ԭ���𡭡�
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

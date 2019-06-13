#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode* left;
	TNode* right;
};
typedef TNode *Position;
typedef Position Bintree;
//�ҵ��ɻ󣺾Ͳ��ù���������Ŷ
Bintree Insert(int x, Bintree bst){
	if (bst == NULL){
		bst = new TNode;
		bst->data = x;
		bst->left = NULL;
		bst->right = NULL;
	}
	else if (bst->data > x)bst->left =Insert(x,bst->left);
	else bst->right = Insert(x, bst->right);
	return bst;
}
bool IsSameTree(Bintree root1, Bintree root2){
	//��null�����
	if (root1&&!root2)return false;
	else if (!root1&&!root2)return true;
	//��null�����
	if (root1->data != root2->data)return false;
	else if (IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right))return true;
	else return false;
}
int main(){
    int N,L,temp;
	cin >> N;
    while(N){//ĳ���������
		cin >> L;
		Bintree root1 = NULL;
		for (int i = 0; i < N; i++){
			cin >> temp;
			root1=Insert(temp, root1);
		}
		for (int s = 0; s < L; s++){
			Bintree root2 = NULL;
			for (int i = 0; i < N; i++){
				cin >> temp;
				root2 = Insert(temp, root2);
			}
			if(IsSameTree(root1, root2))cout<<"Yes"<<endl;
			else cout << "No" << endl;
		}	
		cin >> N;
    }
	system("pause");
	return 0;
}
#include<cstdio>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
int index = 0;
int flag = 0;
void CreateTree(int tree[3][31],int size,int root){
	string str;
	int num;
	if (size - 1 == index){
		tree[2][index] = -1;
		tree[1][index] = -1;
		return;
	}
	//left tree
	cin >> str;
	if (str == "Push"){
		cin >> num;
		tree[0][++index] = num;
		tree[1][root] = index;
		CreateTree(tree,size, index);
	}
	else{
		tree[1][root] = -1;
	}
	//right tree
	cin >> str;
	if (str == "Push"){
		cin >> num;
		index++;
		tree[0][index] = num;
		tree[2][root] = index;
		CreateTree(tree,size,index);
	}
	else{
		tree[2][root] = -1;
	}
}
void PostOrder(int tree[3][31],int root){
	if (tree[1][root] != -1)PostOrder(tree, tree[1][root]);
	if (tree[2][root] != -1)PostOrder(tree, tree[2][root]);
	if (flag)cout << " ";
	cout << tree[0][root];
	flag = 1;
}
int main(){
	int m, temp;
	cin >> m;
	int tree[3][31];
	string str;
	cin >> str >> temp;
	tree[0][0] = temp;//root
	CreateTree(tree, m,0);
	PostOrder(tree, 0);
	system("pause");
	return 0;
}
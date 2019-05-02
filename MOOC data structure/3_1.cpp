#include<cstdio>
#include<iostream>
using namespace std;
struct bitree{
	char data;
	int left;
	int right;
};
bool judge(int root0,int root1,int size, bitree test[2][11]){
	if (root0 == 10 && root1 == 10)return true;		//到底了
	if (test[0][root0].data != test[1][root1].data)return false;		//不相等
	if ((judge(test[0][root0].left, test[1][root1].left, size, test) || judge(test[0][root0].left, test[1][root1].right, size, test)) && (judge(test[0][root0].right, test[1][root1].left, size, test) || judge(test[0][root0].right, test[1][root1].right, size, test)))return true;
	else return false;
}
int findroot(bool mark[11],int size){
	for (int i = 0; i < size; i++){
		if (!mark[i])return i;
	}
}
bool isomorphism(){
	int m, n;
	char temp;
	bitree test[2][11];
	bool mark[2][11] = { false };
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> test[0][i].data;
		cin >> temp;
		if (temp == '-')test[0][i].left = 10;
		else {
			test[0][i].left = temp - '0';
			mark[0][temp - '0'] = true;
		}
		cin >> temp;
		if (temp == '-')test[0][i].right = 10;
		else {
			test[0][i].right = temp - '0';
			mark[0][temp - '0'] = true;
		}
	}
	cin >> n;
	if (m != n)return false;
	if (!m&&!n)return true;//空树
	for (int i = 0; i < m; i++){
		cin >> test[1][i].data;
		cin >> temp;
		if (temp == '-')test[1][i].left =10;
		else{
			test[1][i].left = temp - '0';
			mark[1][temp - '0'] = true;
		}
		cin >> temp;
		if (temp == '-')test[1][i].right = 10;
		else{
			test[1][i].right = temp - '0';
			mark[1][temp - '0'] = true;
		}
	}
	return judge(findroot(mark[0], m), findroot(mark[1], m), m, test);
}
int main(){
	if (isomorphism())cout << "Yes" << endl;
	else cout << "No" << endl;
	system("pause");
	return 0;
}
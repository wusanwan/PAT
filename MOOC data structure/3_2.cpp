#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

int main(){
	int m;
	cin >> m;
	int a[3][10]; //no,left,right
	bool mark[10] = { false };
	for (int i = 0; i < m; i++){
		a[0][i] = i;
		char temp;
		cin >> temp;
		if (temp == '-')a[1][i]= 10;
		else {
			a[1][i] = temp - '0';
			mark[temp - '0'] = true;
		}
		cin >> temp;
		if (temp == '-')a[2][i] = 10;
		else {
			a[2][i] = temp - '0';
			mark[temp - '0'] = true;
		}
	}
	int i;
	for (i = 0; i < m;i++)
		if (!mark[i])break;
	queue<int> q;
	q.push(i);
	int flag = 0;
	while (q.size()>0){
		if (a[1][q.front()] == 10 && a[2][q.front()] == 10){
			if (flag)cout << " ";
			cout << a[0][q.front()];
			flag = 1;
		}
		if (a[1][q.front()] != 10)q.push(a[1][q.front()]);
	    if (a[2][q.front()] != 10)q.push(a[2][q.front()]);
		q.pop();
	}
	system("pause");
	return 0;
}
//可以更简略把 vector的两个直接省略，在求diff的一行里直接求出total时间。
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int floor[101];
	floor[0] = 0;  //考虑一开始的情况。
	int N,TotalTime=0,TotalUp=0,TotalDown=0;
	//将问题拆分为上楼和下楼两个过程
	vector<int>up;
	vector<int>down;
	scanf("%d", &N);
	for (int i = 1; i < N+1; i++){
		scanf("%d", &floor[i]);
		int diff = floor[i] - floor[i - 1];
		if (diff >= 0)
			up.push_back(diff);
		else
			down.push_back(0 - diff);
	}
	for (vector<int>::iterator it = up.begin(); it!= up.end(); it++)
		TotalUp += *it;
	for (vector<int>::iterator it = down.begin(); it!= down.end(); it++)
		TotalDown += *it;
	TotalTime = N * 5 + TotalUp * 6 + TotalDown * 4;
	printf("%d", TotalTime);
	//system("pause");
	return 0;
}

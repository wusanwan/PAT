//���Ը����԰� vector������ֱ��ʡ�ԣ�����diff��һ����ֱ�����totalʱ�䡣
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int floor[101];
	floor[0] = 0;  //����һ��ʼ�������
	int N,TotalTime=0,TotalUp=0,TotalDown=0;
	//��������Ϊ��¥����¥��������
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

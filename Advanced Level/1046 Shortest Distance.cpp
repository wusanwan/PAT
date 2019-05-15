//1046 Shortest Distance （20 分）
#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std; //用库千万别忘
int ShortestDistances(int mark[], int start, int end,int length){
	int leftway=0, rightway=0;
	if (start > end)swap(start, end);
	if (start == end)return 0;
	rightway = mark[end - 1] - mark[start - 1];
	leftway = length - rightway;
	return min(leftway, rightway);
}
int main(){
	//input
	int exits,questions,length=0;
	scanf("%d", &exits);
	int circle[100000];
	int mark[100001];
	mark[0] = 0;
	for (int i = 0; i < exits; i++){
		scanf("%d", &circle[i]);
		mark[i+1] = mark[i] + circle[i];
	}
	length = mark[exits];
	scanf("%d", &questions);
	//process
	for (int i = 0; i < questions; i++){
		int start, end;
		scanf("%d %d", &start,&end);
		printf("%d\n", ShortestDistances(mark,start,end,length));
	}
	system("pause");
	return 0;
}
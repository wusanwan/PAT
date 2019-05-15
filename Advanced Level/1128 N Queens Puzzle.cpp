//1128 N Queens Puzzle
#include<cstdio>
#include<stdlib.h>
#pragma warning(disable:4996)
#include<cmath>
#include<algorithm>
using namespace std;
bool IsNQueen(int queen[], int num){
	for (int i = 0; i < num - 1; i++)
		for (int j = i + 1; j < num; j++)
			if (j - i == abs(queen[i] - queen[j]))return false;
	sort(queen, queen + num);
	for (int i = 0; i < num - 1; i++)if (queen[i] == queen[i + 1])return false;
	return true;
}
int main(){
	int N;
	int queen[200][1000];
	int num[200];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num[i]);
		for (int j = 0; j < num[i]; j++){
			scanf("%d", &queen[i][j]);
		}
		if (IsNQueen(queen[i],num[i]))printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}

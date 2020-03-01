//1105 Spiral Matrix （25 分）
#pragma warning (disable:4996)
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int N,num[10000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}
	sort(num, num +	N,cmp);
	//找最适合长宽,如果从sqrt中间找会更快点
	int row, col;
	for (row = ceil(sqrt(N)); row<=N; row++){
		if (N%row == 0)break;
	}
	col = N / row;
	//output
	int out[200][200],r=row,c=col,start=0,circle,round=0;
	for (int i = 0; i < N; i++){
		circle = r * 2 + c * 2 - 4;
		if (i - start < c)out[round][round+i-start] = num[i];
		else if (i - start < r + c - 1)out[round + i - start - c + 1][round+ c - 1] = num[i];
		else if (i - start < r + 2 * c - 2)out[round+r - 1][round+c-(i-start-r-c+1)-2] = num[i];
		else if (i - start < circle - 1)out[round+r - (i - start - r - 2 * c + 4)][round] = num[i];
		else {//i-start==circle-1
			out[round+r - (i - start - r - 2 * c + 4)][round] = num[i];
			start += circle;
			round++;
			r -= 2;
			c -= 2;
		}
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			printf("%d", out[i][j]);
			if (j != col - 1)printf(" ");
			else printf("\n");
		}
	}
	system("pause");
	return 0;
}
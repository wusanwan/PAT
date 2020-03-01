//1132 Cut Integer
#include<cstdio>
#include<stdlib.h>
#pragma warning(disable:4996)
#include<cmath>
#include<algorithm>
using namespace std;
bool CanWeCutIt(int num){
	int digit = 10;
	int left = 0, right, val, init = num;
	while (digit){//ÕÒµ½Î»Êý
		if (num / pow(10, digit-1) > 1)break;
		else digit--;
	}
	for (int i = digit; i > digit / 2; i--){
		val = num / pow(10, i - 1);
		num = num - val*pow(10, i - 1);
		left = left * 10 + val;
	}
	right = init - left*pow(10, digit / 2);
	if (left*right == 0)return false;
	if (init % (left*right) == 0)return true;
	else return false;
}
int main(){
	int N,num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		if (CanWeCutIt(num))printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}

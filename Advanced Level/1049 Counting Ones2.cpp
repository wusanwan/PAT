//1049 Counting Ones （30 分） 向前向后版
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N, result = 0, digit = 9,high=0,low;
	scanf("%d", &N);
	int value[10];	
	low = N;
	for (int i = 9; i >=0; i--){//计算每位的值
		value[i] = low / pow(10, i);
		result += high * pow(10,i);
		high = high * 10 + value[i];
		low -= pow(10, i)*value[i];
		if (value[i] > 1){
			result += pow(10, i);
		}
		else if (value[i] == 1){
			result += low;
			result++;
		}
		else{
			continue;
		}
	}
	printf("%d", result);
	system("pause");
	return 0;
}
//1049 Counting Ones ��30 �֣��Լ�д������
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N,result=0;
	scanf("%d", &N);
	int counts[10];//0-10^index-1,10^index����1����
	counts[0] = 1;
	int value[10],IsOne[10];
	fill(IsOne, IsOne + 10, 0);
	for (int i = 1; i<10; i++)
		counts[i] = counts[i - 1] * 10 + pow(10, i);
	for (int i = 9; i > 0; i--){//����ÿλ�ϵ�ֵ,��λ����N��
		value[i] = N / pow(10, i);
		N = N - value[i] * pow(10, i);
		if (value[i] > 1){
			result += counts[i - 1] * value[i]+ pow(10,i);
		}
		if (value[i] == 1){
			result += counts[i - 1];
			IsOne[i] =1;
		}
	}
	//�����λ��
	if(N >= 1)result++;
	//׷����Ϊ1��ɵ�����
	int temp=N;
	for (int i = 1; i < 10; i++){
		if (IsOne[i])result = temp + result +1;
		temp += value[i] * pow(10, i);
	}
	printf("%d", result);
	system("pause");
	return 0;
}
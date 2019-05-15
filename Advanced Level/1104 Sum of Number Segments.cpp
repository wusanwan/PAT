//1104 Sum of Number Segments （20 分）
#include<cstdio>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(){
	int N;//本质不是怎么排序而是0.1，0.2，0.3，0.4这种各出现几次
	float temp,sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%f", &temp);
		sum += temp*(N - i)*(i + 1);
	}
	printf("%.2f", sum);
	system("pause");
	return 0;
}
 


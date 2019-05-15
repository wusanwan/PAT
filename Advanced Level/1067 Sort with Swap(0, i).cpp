//1067 Sort with Swap(0, i) 
#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
#include<algorithm>
using namespace std;
int main(){
	int N,number[100000],count=0,circle=1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &number[i]);
	while (circle){
		int flag = 1;
		for (int i = 0; i < N - 1; i++){//找换一次两个都满足的
			for (int j = i+1; j < N; j++){
				if (number[i] == j&&number[j] == i){
					count++;
					flag = 0;
					swap(number[i], number[j]);
					break;
				}
			}
		}
		if (flag){//找不到的话就换一次满足一个
			for (int i = 0; i < N; i++){
				if (number[i] != i){
					int j = i+1;
					while (number[j] !=i)j++;
					swap(number[i], number[j]);
					count++;
					break;
				}
			}
		}
		for (int i= 0; i < N; i++){//检验
			if (number[i] != i)break;
			if (i == N - 1)circle = 0;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}
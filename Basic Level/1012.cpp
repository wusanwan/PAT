#include<cstdio>
#include<cstdlib>
#include<cmath>
#pragma warning(disable:4996)
int main(){
	int n,num, c2=0,c4=0,result[5] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &num);
		if (num % 10 == 0)result[0] +=num;
		if (num % 5 == 1){
			result[1] += pow(-1, c2)*num;
			c2++;
		}
		if (num % 5 == 2)result[2]++;
		if (num % 5 == 3){
			result[3] += num;
			c4++;
		}
		if (num % 5 == 4){
			if (num > result[4])result[4] = num;
		}
	}
	for (int i = 0; i < 5; i++){
		if (i != 0)printf(" ");
		if (i == 1 && c2 == 0|| i != 1 && result[i] == 0)printf("N");
		else if (i == 3){
			float temp = (float)result[3] / c4;	//注意要写强制类型转换。
			printf("%.1f", temp);
		}
		else
			printf("%d", result[i]);
	}
	system("pause");
	return 0;
}
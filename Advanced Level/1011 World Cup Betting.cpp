//1011 World Cup Betting （20 分）
#include<cstdio>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int main(){
	float odds[3][3], product = 1;
	int decision[3];
	fill(decision, decision + 3, 0);//语法上也是左闭右开
	char a[4] = "WTL"; //记得留一个空存\0
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			scanf("%f", &odds[i][j]);
			if (odds[i][decision[i]] < odds[i][j])decision[i] = j;
		}
		product *= odds[i][decision[i]];
		printf("%c",a[decision[i]]);
	}
	printf("%.2f", product*0.65*2 - 2);
	system("pause");
	return 0;
}
//1001 A + B Format （20 分）
#pragma warning(disable:4996)
#include<cstdio>
#include<string>
#include<string.h>
#include<cstdlib>
using namespace std;
int main(){
	int a, b, sum;
	char s[10];
	scanf("%d %d", &a, &b);
	sum = a + b;
	sprintf(s, "%d", sum);
	string str=s;
	if (sum < 0){//处理符号
		printf("-");
		str.erase(0,1);
	}
	int u = str.length() % 3;
	for (int i = 0; i < str.length(); i++){//第i个数字
		putchar(str[i]);
		if (i != str.length() - 1 &&(i-u+1)%3==0)printf(",");
	}
	system("pause");
	return 0;
}

//1005 Spell It Right （20 分）
#pragma warning(disable:4996)
#include<cstdio>
#include<string.h>
#include<cstdlib>
int main(){
	char N[101],S[102];
	int sum = 0;
	scanf("%s", &N);
	for (int i = 0; i < strlen(N); i++)
		sum += N[i] - '0';
	sprintf(S, "%d", sum);//sum的字符串形式如15
	char english[10][10] = { "zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine" };
	for (int i = 0; i < strlen(S); i++){
		printf("%s", english[S[i] - '0']);
		if (i != strlen(S) - 1)printf(" ");
	}
	system("pause");
	return 0;
}
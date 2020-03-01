//1019 General Palindromic Number
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
using namespace std;
bool IsPalindromic(int digit[], int i){
	for (int j = 0; j < i / 2; j++){
		if (digit[j] != digit[i -1- j])return false;
	}
	return true;
}
int main(){ 
	int num, base;
	scanf("%d %d", &num, &base);
	int digit[129];
	int i = 0;
	do{
		digit[i] = num%base;
		i++;
		num = num / base;
	} while (num != 0);
	if (IsPalindromic(digit, i))printf("Yes\n");
	else printf("No\n");
	printf("%d", digit[i-1]);
	i-=2;
	for (; i >= 0; i--)
		printf(" %d", digit[i]);
	system("pause");
	return 0;
}

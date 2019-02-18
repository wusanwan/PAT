#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, i = 0, need;
	char ch;
	cin >> n >> ch;
	while (i*i *2 - 1<=n){
		i++;
	}
	i--;
	for (int j = i; j >= 1; j--){
		for (int k = 0; k < i - j;k++)printf(" ");
		for (int k = 0; k < 2 * j - 1; k++)printf("%c", ch);
		printf("\n");
	}
	for (int j = 2; j <= i; j++){
		for (int k = 0; k < i - j; k++)printf(" ");
		for (int k = 0; k < 2 * j - 1; k++)printf("%c", ch);
		printf("\n");
	}
	printf("%d", n - i * i * 2 + 1);
	system("pause");
	return 0;
}
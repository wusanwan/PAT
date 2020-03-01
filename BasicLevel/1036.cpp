#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n;
	char ch;
	cin >> n >> ch;
	for (int j = 0; j<n; j++){
		putchar(ch);
	}
	printf("\n");
	for (int j = 0; j < int(n/2.0+0.5)-2; j++){
		putchar(ch);
		for (int k = 0; k <n-2; k++)printf(" ");
		putchar(ch);
		printf("\n");
	}
	for (int j = 0; j < n; j++){
		putchar(ch);
	}
	system("pause");
	return 0;
}
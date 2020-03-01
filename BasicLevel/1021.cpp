#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	string num;
	cin >> num;
	int a[10] = { 0 };
	for (int i = 0; i < num.length(); i++){
		a[num[i] - '0']++;
	}
	for (int i = 0; i < 10; i++){
		if (a[i] == 0)continue;
		printf("%d:%d\n", i, a[i]);
	}
	system("pause");
	return 0;
}
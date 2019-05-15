//1031 Hello World for U （20 分）
#include<stdio.h>
#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int main(){
	string str;
	cin >> str;
	int x = (str.length() + 2) / 3;		//高
	int y = str.length() - 2 * x + 2;		//宽
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			if (i == x - 1)		//最底下那排
				putchar(str[x - 1 + j]);
			else{//其他排
				if (j == 0)putchar(str[i]);
				else if (j == y - 1)printf("%c\n",str[str.length() - 1 - i]);
				else putchar(' ');
			}
		}
	}
	system("pause");
	return 0;
}
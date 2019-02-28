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
	int sum = 0,flag=0;
	for (int i = 0; i < num.length(); i++){
		sum+=num[i]-'0';
	}
	num = to_string(sum);
	for (int i = 0; i < num.length(); i++){
		if (i)printf(" ");
		int key =num[i] - '0';
		if (key == 0)printf("ling");
		else if (key == 1)printf("yi");
		else if (key == 2)printf("er");
		else if (key == 3)printf("san");
		else if (key == 4)printf("si");
		else if (key == 5)printf("wu");
		else if (key == 6)printf("liu");
		else if (key == 7)printf("qi");
		else if (key == 8)printf("ba");
		else printf("jiu");
	}
	system("pause");
	return 0;
}
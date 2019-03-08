#pragma warning (disable:4996)
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int main(){
	char week[8][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };//string不可以？
	string hour = "0123456789ABCDEFGHIJKLMN";
	string str[4];
	for (int i = 0; i < 4; i++)
		cin >> str[i];
	int cap = 0, pos;
	for (int i = 0; i < str[0].length(); i++){
		if ((str[0][i] >= 'A'&&str[0][i] <= 'N' || str[0][i] >= '0'&&str[0][i] <= '9') && str[0][i] == str[1][i]){
			if (str[0][i] >= 'A'&&str[0][i] <= 'G'&&!cap){
				printf("%s ", week[str[0][i] - 'A']);//第一个相同
				cap++;
			}
			else if (cap == 1){
				cap++;
				int k = hour.find(str[0][i]);
				if (k < 10)printf("0");
				printf("%d", k);
			}
			else
				continue;
		}
	}
	for (int i = 0; i < str[2].length(); i++){
		if ((str[2][i] >= 'a'&&str[2][i] <= 'z' || str[2][i] >= 'A'&&str[2][i] <= 'Z') && str[2][i] == str[3][i]){
			printf(":");
			if (i < 10)printf("0");
			printf("%d", i);
			break;
		}
	}
	system("pause");
	return 0;
}

#include<cstdio>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	string str;
	cin >> str;
	int num[6] = { 0 };
	for (int i = 0; i < str.length(); i++){
		if (str[i] == 'P')num[0]++;
		else if(str[i] == 'A')num[1]++;
		else if (str[i] == 'T')num[2]++;
		else if (str[i] == 'e')num[3]++;
		else if (str[i] == 's')num[4]++;
		else if (str[i] == 't')num[5]++;
	}
	while (num[0] || num[1] || num[2] || num[3] || num[4] || num[5]){
		if (num[0]>0){
			num[0]--;
			printf("P");
		}
		if (num[1]>0){
			num[1]--;
			printf("A");
		}
		if (num[2]>0){
			num[2]--;
			printf("T");
		}
		if (num[3]>0){
			num[3]--;
			printf("e");
		}
		if (num[4]>0){
			num[4]--;
			printf("s");
		}
		if (num[5]>0){
			num[5]--;
			printf("t");
		}
	}
	system("pause");
	return 0;
}
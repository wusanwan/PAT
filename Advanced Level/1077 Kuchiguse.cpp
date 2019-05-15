//1077 Kuchiguse
#pragma warning (disable:4996)
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	getchar();//ÈÓµô»»ÐÐ·û
	string list[100];
	string kuchiguse;
	for (int i = 0; i < N; i++){
		getline(cin, list[i]);
	}
	int i,flag=0;
	for (i = list[0].length(); i>=1&&!flag; i--){//kuchiguse
		kuchiguse = list[0].substr(list[0].length()-i,i);
		for (int j = 1; j < N; j++){//compare
			if (list[j].find(kuchiguse) != list[j].length() - i)
				break;
			if (j == N - 1){
				flag = 1;
				cout << kuchiguse;
			}
		}
	}
	if (!flag)cout << "nai";
	system("pause");
	return 0;
}
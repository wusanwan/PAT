#include<cstdio>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int N,teamnum,member,grade;
	cin >> N;
	int team[1001] = { 0 };
	for (int i = 0; i < N; i++){
		cin >> teamnum;
		cin.ignore(1) >> member >> grade;			//·ÖÐÐ
		team[teamnum] += grade;
	}
	int high = 0;
	for (int i = 1; i < 1001; i++){
		if (team[i]>team[high])high = i;
	}
	cout << high << " " << team[high];
	system("pause");
	return 0;
}
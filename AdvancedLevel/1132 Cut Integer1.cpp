//1132 Cut Integer  string ∞Ê
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string s,sleft,sright;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		int half = s.length() / 2;
		int left, right,ss;
		sleft = s.substr(0,half);
		sright = s.substr(half, half);//Œª÷√≥§∂»
		sscanf(sleft.c_str(), "%d", &left);
		sscanf(sright.c_str(), "%d", &right);
		sscanf(s.c_str(), "%d", &ss);
		if (left*right&& ss% (left*right)==0)printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}
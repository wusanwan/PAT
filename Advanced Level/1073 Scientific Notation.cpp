//1073 Scientific Notation
#pragma warning (disable:4996)
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string str,num,exp;
	cin >> str;
	int pos;//找E
	pos=str.find("E");
	num = str.substr(1, pos);
	exp = str.substr(pos + 1, str.length());
	float n; int e;
	sscanf(num.c_str(), "%f", &n);
	sscanf(exp.c_str(), "%d", &e);
	//正负，只有负的需要输出
	if (str[0] = '-')printf("-");
	if (e >= 0){}


}
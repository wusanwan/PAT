//1026 Table Tennis 
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct record{
	string name, time, statu;
	int month;
};
bool cmp(record a, record b){
	if (a.name == b.name)return a.time < b.time;
	else return a.name < b.name;
}
int main(){
	int N;
	system("pause");
	return 0;
}
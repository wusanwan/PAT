#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
void time(int i){
	int total = i / 100.0 + 0.5;//土法四舍五入
	int hh, mm, ss;
	hh = (int)total / 3600;
	total -= hh * 3600;
	mm = (int)total / 60;
	ss = total - mm * 60;
	printf("%02d:%02d:%02d",hh,mm,ss);
}
int main(){
	int a, b,diff;
	cin >> a >> b;
	diff = b - a;
	time(diff);
	system("pause");
	return 0;
}
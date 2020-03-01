#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	string str;
	cin >> str;
	int t=0,sumAT=0,sumPAT=0;
	for (int i = str.size() - 1; i >= 0; i--){
		if (str[i]== 'T')t++;
		else if (str[i] == 'A')sumAT += t;
		else {
			sumPAT += sumAT;
			sumPAT = sumPAT % 1000000007;
		}
	}
	cout << sumPAT;
	system("pause");
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	string s1, s2;
	int ch[256] = { 0 };
	cin >> s1 >> s2;
	int flag = 1, sum = 0;
	for (int i = 0; i< s1.length(); i++){
		ch[s1[i]]++;
	}
	for (int i = 0; i< s2.length(); i++){
		if (ch[s2[i]] > 0)ch[s2[i]]--;
		else{
			flag = 0;
			sum++;
		}
	}
	if (flag)cout << "Yes " << s1.length() - s2.length();
	else cout << "No " << sum;
	system("pause");
	return 0;
}
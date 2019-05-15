//1092 To Buy or Not to Buy
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<iostream>
using namespace std;
int main(){
	string a, b;
	cin >> a>>b;
	map<char, int>mp;
	for (int i = 0; i < a.length(); i++)mp[a[i]]++;
	int count = 0;
	for (int i = 0; i < b.length(); i++){
		if (mp[b[i]] >= 1)mp[b[i]]--;
		else count++;
	}
	if (count)printf("No %d", count);
	else printf("Yes %d", a.length() - b.length());
	system("pause");
	return 0;
}
#include<cstdlib>
#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	vector<string>words;
	string temp;
	while (cin >> temp){
		words.push_back(temp);
	}
	for (int i = words.size() - 1; i >= 0; i--){
		cout << words[i];
		if (i != 0)cout << " ";
	}
	system("pause");
	return 0;
}
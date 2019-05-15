//1050 String Subtraction
#pragma warning(disable:4996)
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int chara[256] = { 0 };
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < b.length(); i++)
		chara[b[i]]++;
	for (int i = 0; i < a.length(); i++){
		if (chara[a[i]] == 0)
			cout << a[i];
	}	
	cout <<endl;
	system("pause");
	return 0;
}
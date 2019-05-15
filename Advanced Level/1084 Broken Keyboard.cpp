//1084 Broken Keyboard
#pragma warning(disable:4996)
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string a, b;
	cin >> a >> b;
	bool chara[256] = { false };
	for (int i = 0; i < b.length(); i++){
		if (b[i] >= 'a'&&b[i] <= 'z')b[i] = b[i] - 'a' + 'A';
		chara[b[i]] = true;
	}
	for (int i = 0; i < a.length(); i++){
		if (a[i] >= 'a'&&a[i] <= 'z')a[i] = a[i] - 'a' + 'A';
		if (chara[a[i]] == false){
			cout << a[i];
			chara[a[i]] = true;
		}
	}
	system("pause");
	return 0;
}

#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
void print(char ch, int t){
	while (t--)
		cout << ch;
}
int main(){
	string num;
	cin >> num;
	for (int i = 0; i < num.length(); i++){
		int digit = num[i] - '0';
		if (num.length() - i == 3)print('B', digit);
		else if (num.length() - i == 2)print('S', digit);
		else{
			for (int i = 1; i <= digit; i++){
				cout << i;
			}
		}
	}
	system("pause");
	return 0;
}
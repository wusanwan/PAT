#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n;
	cin >> n;
	string choice;
	for (int i = 0; i < n; i++){
		for (int j = 0; j<4; j++){
			cin >> choice;
			if (choice[2] == 'T')cout <<choice[0]-'A'+1;
		}
	}
	system("pause");
	return 0;
}
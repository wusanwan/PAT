#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, m,temp;
	cin >> m >> n;
	int answer[100], score[100];
	for (int i = 0; i < n; i++)
		cin >> score[i];
	for (int i = 0; i < n; i++)
		cin >> answer[i];
	for (int i = 0; i < m; i++){
		int result = 0;
		for (int j = 0; j < n; j++){
			cin >> temp;
			if (temp == answer[j])result += score[j];
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}
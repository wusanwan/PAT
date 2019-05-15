//1149 Dangerous Goods Packaging
#pragma warning(disable:4996)
#include<cstdlib>
#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int M, N, K, flag = 0, count = 0;
	string temp;
	scanf("%d %d %d", &M, &N, &K);
	map<string, int>mp;
	for (int i = 0; i < M; i++){
		cin >> temp;
		if (K - 1 == i){//first time
			cout << temp << endl;
			flag = 1;
			mp[temp] = -1;
		}
		else if (flag &&mp[temp] != -1){
			count++;
			if (count == N){
				cout << temp << endl;
				count = 0;
				mp[temp] = -1;
			}
		}
	}
	if (!flag)printf("Keep going...");
	system("pause");
	return 0;
}
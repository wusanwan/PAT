//1100 Mars Numbers
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int main(){
	string temp;
	vector<string>str;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		cin.getline();
	}
		
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &now);
			color[now]++;
			if (color[now]>half)printf("%d", now);
		}
	}
	system("pause");
	return 0;
}
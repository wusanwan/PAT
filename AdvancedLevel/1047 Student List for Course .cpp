//1047 Student List for Course 
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N, K,num,index;
	string name;
	scanf("%d %d", &N, &K);
	vector<string>course[2501];
	for (int i = 0; i < N; i++){
		cin >> name >> num;
		for (int j = 0; j < num; j++){
			scanf("%d", &index);
			course[index].push_back(name);
		}
	}
	for (int i = 1; i <= K; i++){
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, course[i].size());
		for (int j = 0; j < course[i].size(); j++)
			printf("%s\n", course[i][j].c_str());
	}
	system("pause");
	return 0;
}
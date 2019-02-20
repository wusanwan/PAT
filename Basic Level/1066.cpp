#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, m, temp,a,b,k;
	int row[500];
	cin >> m >> n>>a>>b>>k;
	for (int i = 0; i < m; i++){
		int result = 0;
		for (int j = 0; j < n; j++){
			cin >>row[j];
			if (row[j]<=b &&a<=row[j])row[j]=k;
		}
		for (int j = 0; j < n; j++){//其实也可以当场输出。
			if (j != 0)printf(" ");
			printf("%03d", row[j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int M, N, TOL, temp, x, y, num = 0;
	cin >> M >> N >> TOL;
	vector<int>pixel[1000];
	map<int,int> exist;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> temp;
			pixel[i].push_back(temp);
			exist[temp]++;
		}
	}
	for (int i = 0; i < N  &&num<2; i++){//宁可8条if也不要分开循环
		for (int j = 0; j < M&&num<2; j++){
			if (exist[pixel[i][j]]>1)continue;
			if (i != 0 && j != 0 && abs (pixel[i - 1][j - 1] - pixel[i][j]) <= TOL)continue;
			if (i != 0 && abs(pixel[i - 1][j] - pixel[i][j]) <= TOL)continue;
			if (i!=0 &&j!=M-1&&abs(pixel[i - 1][j + 1] - pixel[i][j]) <= TOL)continue;
			if (j != 0 && abs(pixel[i][j - 1] - pixel[i][j]) <= TOL)continue;
			if (j!= M - 1 && abs(pixel[i][j + 1] - pixel[i][j]) <= TOL)continue;
			if (i != N - 1 && j != 0 && abs(pixel[i + 1][j - 1] - pixel[i][j]) <= TOL)continue;
			if (i != N - 1 && abs(pixel[i + 1][j] - pixel[i][j]) <= TOL)continue;
			if (i !=N-1 && j!=M-1 &&abs(pixel[i + 1][j + 1] - pixel[i][j]) <= TOL)continue;
			if (num == 0){
				num++;
				x = i + 1;
				y = j + 1;
			}
			else{
				num++;
			}
		}
	}
	if (num == 1)cout<<"(" << y << ", " << x << ") :" << pixel[x - 1][y - 1];
	else if (num == 0)cout << "Not Exist";
	else cout << "Not Unique";
	system("pause");
	return 0;
}
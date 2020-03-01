//1054 The Dominant Color
#include<cstdio>
#include<cstdlib>
#include<map>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int M, N,now;
	scanf("%d %d", &M, &N);
	map<int, int>color;
	int half = N*M / 2;
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &now);
			color[now]++;
			if (color[now]>half)printf("%d",now);	
		}
	}
	system("pause");
	return 0;
}
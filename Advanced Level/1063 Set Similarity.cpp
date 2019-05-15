//1063 Set Similarity 
#include<cstdio>
#include<cstdlib>
#include<set>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N,num,temp,K,a,b;
	float rate,total;
	scanf("%d", &N);
	set<int>sets[50];
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		for (int j = 0; j < num; j++){
			scanf("%d", &temp);
			sets[i].insert(temp);
		}
	}
	set<int>::iterator it;
	scanf("%d", &K);
	for (int i = 0; i < K; i++){
		scanf("%d %d", &a, &b);
		int result = 0;
		for (it = sets[a - 1].begin(); it != sets[a - 1].end(); it++)
			if (sets[b - 1].find(*it) != sets[b - 1].end())result++;
		total = sets[a - 1].size() + sets[b - 1].size();
		rate = result/(total-result);
		printf("%.1f%%\n", rate * 100);
	}
	system("pause");
	return 0;
}
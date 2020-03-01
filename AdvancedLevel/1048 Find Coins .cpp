//1048 Find Coins 
#pragma warning(disable:4996)
#include<cstdlib>
#include<set>
#include<cstdio>
using namespace std;
int main(){
	int value[1000] = { 0 };
	int N, M,temp;
	scanf("%d %d", &N, &M);
	set<int>solution;
	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		if (M - temp <= 0 )continue;
		if(value[M-temp]==1){
			solution.insert(temp);
			solution.insert(M - temp);
		}
		else value[temp] = 1;
	}
	if (solution.size() == 0)printf("No Solution");
	else printf("%d %d", *solution.begin(), M - *solution.begin());
	system("pause");
	return 0;
}
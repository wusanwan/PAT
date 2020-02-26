//1125 Chain the Ropes
#include<cmath>
#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
#include<algorithm>
using namespace std;
int main(){
	int N,result;
	scanf("%d", &N);
	int ropes[10000];
	for (int i = 0; i < N; i++)
		scanf("%d", &ropes[i]);
	sort(ropes, ropes + N);
	double sum = ropes[0];
	for (int i = 1; i < N; i++){
			sum += ropes[i];
			sum = sum / 2.0;
	}
	result = floor(sum);
	printf("%d", result);
	system("pause");
	return 0;
}

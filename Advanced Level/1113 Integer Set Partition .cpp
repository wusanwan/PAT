//1113 Integer Set Partition 
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int N,clip,s1=0,s2=0,j;
	scanf("%d", &N);
	int list[100000];
	for (int i = 0; i < N; i++)
		scanf("%d", &list[i]);
	sort(list, list + N);
	clip= ceil(N / 2.0);	//注意这里是N/2.0
	for (j = 0; j < N - clip; j++)
		s1 += list[j];
	for (; j < N; j++)
		s2 += list[j];
	printf("%d %d", 2 * clip - N, abs(s2 - s1));
	system("pause");
	return 0;
}
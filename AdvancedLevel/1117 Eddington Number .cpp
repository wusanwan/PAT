//1117 Eddington Number 
#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int rides[100000];//int”–10^9
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &rides[i]);
	sort(rides, rides + N);//ƒ¨»œµ›‘ˆ≈≈–Ú
	int i;
	for (i = N; i >= 0; i--){
		if (rides[N-i]>i)break;
	}
	if (i==-1)printf("0");
	else printf("%d", i);
	system("pause");
	return 0;
}
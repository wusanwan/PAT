//1065 A+B and C (64bit) 
#include<cstdio>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(){
	int N,i;
	long long A, B, C;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%lld %lld %lld", &A, &B, &C);
		printf("Case #%d: ", i);
		if (A + B > C)printf("true\n");
		else printf("false\n");
	}
	system("pause");
	return 0;
}

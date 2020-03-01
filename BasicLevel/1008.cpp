#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
int main(){
	int n,m,a[100];
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[(i + m)%n]);
	}
	for (int i = 0; i < n; i++){
		if (i != 0)printf(" ");
		printf("%d", a[i]);
	}
	system("pause");
	return 0;
}
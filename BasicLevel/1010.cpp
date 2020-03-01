#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
int main(){
	int n, m, count = 0;
	while (scanf("%d %d", &n, &m) != EOF){
		if (!m)continue;
		if (count)printf(" ");
		else count = 1;
		printf("%d %d", n*m, m - 1);
	}
	if (!count)printf("0 0");
	system("pause");
	return 0;
}
#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
int main(){
	int n,count=0;
	scanf("%d", &n);
	while (n != 1){
		if (n % 2 == 0)n = n / 2;
		else n = (3 * n + 1) / 2;
		count++;
	}
	printf("%d", count);
	system("pause");
	return 0;
}
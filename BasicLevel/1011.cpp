#include<cstdio>
#include<cstdlib>
#pragma warning(disable:4996)
int main(){
	int n;
	scanf("%d", &n);
	long long a, b, c;
	for (int i = 0; i < n; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("Case #%d: ", i + 1);
		if (a + b> c)printf("true\n");
		else printf("false\n");
	}
	system("pause");
	return 0;
}
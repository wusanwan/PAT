//1037 Magic Coupon
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int a, b,sum=0;
	int A[100000], B[100000];
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
		scanf("%d", &A[i]);
	scanf("%d", &b);
	for (int i = 0; i < b; i++)
		scanf("%d", &B[i]);
	sort(A, A + a);
	sort(B, B + b);
	int alow = 0, blow = 0, ahigh = a - 1, bhigh = b - 1,m,n;
	while (alow<=ahigh&&blow<=bhigh){//只考虑正正负负的情况
		m = A[alow] * B[blow];
		n = A[ahigh] * B[bhigh];
		if (m < 0 && n < 0)break;//全负退出，保证mn至少一个正的
		if (m>n){
			sum += m;
			alow++;
			blow++;
		}
		else{
			sum += n;
			ahigh--;
			bhigh--;
		}
	}	
	printf("%d", sum);
	system("pause");
	return 0;
}
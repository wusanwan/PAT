//1037 Magic Coupon
#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int nc, np,sum=0;
	int coupon[100000];
	int product[100000];
	scanf("%d", &nc);
	for (int i = 0; i < nc;i++)
		scanf("%d", &coupon[i]);
	scanf("%d", &np);
	for (int i = 0; i < np; i++)
		scanf("%d", &product[i]);
	sort(coupon, coupon + nc);
	sort(product, product + np);
	for (int i = 0; product[i] < 0 && coupon[i] < 0 && i<nc && i<np; i++)//考虑两个都负的情况
		sum += product[i] * coupon[i];
	for (int i = 0; product[np - 1 - i]>0 && coupon[nc - 1 - i]>0 && i<nc && i<np; i++)//考虑两个都正的情况
		sum += product[np - 1 - i] * coupon[nc - 1 - i];
	printf("%d", sum);
	system("pause");
	return 0;
}

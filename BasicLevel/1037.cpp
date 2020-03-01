#include<cstdio>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int g1, g2, s1, s2, k1, k2,g3,s3,k3;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	long long diff=g2 * 17 * 29 + s2 * 29 + k2- g1 * 17 * 29 -  s1 * 29 - k1;
	g3 = diff / (29 * 17);
	s3 = (diff - g3 * 29 * 17) / 29;
	k3 = diff % 29;
	if (diff>0)printf("%d.%d.%d", g3, s3, k3);
	else printf("%d.%d.%d", g3, -s3, -k3);
	system("pause");
	return 0;
}
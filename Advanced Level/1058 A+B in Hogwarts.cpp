//1058 A+B in Hogwarts 
#pragma warning(disable:4996)
#include<cstdio>
#include<string.h>
#include<cstdlib>
long long trans1(long long a, long long b, long long c){
	return a * 17 * 29 + b * 29 + c;
}
void trans2(long long sum, long long &a, long long&b, long long&c){
	a = sum / (17 * 29);
	sum -= a * 17 * 29;
	b = sum / 29;
	c = sum % 29;
}
int main(){
	long long hogwarts[2][3];
	for (int i = 0; i < 2;i++)
		scanf("%lld.%lld.%lld", &hogwarts[i][0], &hogwarts[i][1], &hogwarts[i][2]);
	long long sum;
	sum = trans1(hogwarts[0][0], hogwarts[0][1], hogwarts[0][2]) + trans1(hogwarts[1][0], hogwarts[1][1], hogwarts[1][2]);
	long long galleon, sickle, knut;
	trans2(sum, galleon, sickle, knut);
	printf("%lld.%lld.%lld", galleon, sickle, knut);
	system("pause");
	return 0;
}

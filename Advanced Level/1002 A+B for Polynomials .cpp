//1002 A+B for Polynomials
#pragma warning(disable:4996)
#define eps 1E-6
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	float poly[1001];
	fill(poly, poly + 1001, 0.0);
	int terms, exponent,sumterms=0;
	float cofficient;
	for(int i=0;i<2;i++){
		scanf("%d", &terms);
		for (int i = 0; i < terms; i++){
			scanf(" %d %f", &exponent, &cofficient);
			if (fabs(poly[exponent])<eps&&fabs(cofficient)>eps)sumterms++;
			poly[exponent] += cofficient;
			if (fabs(poly[exponent]) < eps)sumterms--; 
		}
	}
	//output
	printf("%d", sumterms);
	for (int i = 1000; i >= 0; i--){
		if (fabs(poly[i])>eps)printf(" %.1d %.1f", i, poly[i]);
	}
	system("pause");
	return 0;
}
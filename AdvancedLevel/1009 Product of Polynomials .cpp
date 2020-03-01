//1009 Product of Polynomials
#pragma warning(disable:4996)
#define eps 1E-6
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct poly{
	int term;
	int exponent[10];
	float cofficient[10];
};
int main(){
	float result[2001];
	fill(result, result + 2001, 0.0);
	int _term,_exponent,sumterms=0;//_表示是第二个
	poly first;
	float _cofficient;
	scanf("%d", &first.term);
	for (int i = 0; i <first.term; i++){
		scanf(" %d %f", &first.exponent[i], &first.cofficient[i]);
	}
	scanf("%d", &_term);
	for (int i = 0; i<_term; i++){
		scanf(" %d %f", &_exponent, &_cofficient);
		for (int j = 0; j < first.term; j++){
			result[_exponent + first.exponent[j]]+= _cofficient*first.cofficient[j];
		}
	}
	//统计总数
	for (int i = 0; i<2001; i++)
		if (fabs(result[i])>eps)sumterms++;
	//output
	printf("%d", sumterms);
	for (int i = 2000; i >= 0; i--){
		if (fabs(result[i])>eps)printf(" %.1d %.1f", i, result[i]);
	}
	system("pause");
	return 0;
}
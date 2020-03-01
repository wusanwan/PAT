#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n,a,b;
	double high=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		if (sqrt(a*a + b*b)>high)high = sqrt(a*a + b*b);
	}
	printf("%.2lf",high);
	system("pause");
	return 0;
}
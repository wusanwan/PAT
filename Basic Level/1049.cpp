#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n;
	cin >> n;
	double a[100000]; //×¢ÒâÒªÓÃdouble
	double sum = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i] * (n - i)*(i + 1);
	}
	printf("%.2lf", sum);
	system("pause");
	return 0;
}
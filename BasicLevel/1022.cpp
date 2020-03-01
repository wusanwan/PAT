#include<iostream>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int a, b, d,sum,i=0;
	cin >> a >> b >> d;
	sum = a + b;
	int digit[32];
	do{
		digit[i++] = sum%d;
		sum = sum / d;
	} while(sum!=0);
	for (int j = i-1; j>=0; j--)
		cout << digit[j];
	system("pause");
	return 0;
}
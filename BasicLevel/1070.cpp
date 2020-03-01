#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n;
	int list[10000];
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	sum = list[0];
	for (int i = 1; i < n; i++){
		sum += list[i];
		sum = sum / 2;
	}
	int s = sum;
	cout << s;
	system("pause");
	return 0;
}
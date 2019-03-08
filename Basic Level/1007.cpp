#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std;
#pragma warning(disable:4996)
#include<algorithm>
#include<map>
#include<vector>
bool IsPrime(int a){
	for (int i = 2; i <= sqrt(a); i++){
		if (a % i == 0)return false;
	}
	return true;
}
int main(){
	int n, count = 0,last=2;//相邻指前一个
	cin >> n;
	for (int i = 3; i <= n; i++){
		if (IsPrime(i)){
			if (i - last == 2)count++;
			last = i;
		}
	}
	cout << count;
		system("pause");
	return 0;
}
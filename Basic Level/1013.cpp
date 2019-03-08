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
	int n, k, count = 0, index = 2;
	cin >> n>>k;
	while (count != k){
		if (IsPrime(index)){
			count++;
			if (count >= n){
				cout << index;
				if (count == k)continue;
				else if ((count - n + 1) % 10 == 0)cout << endl;
				else cout << " ";
			}
		}
		index++;
	}
	system("pause");
	return 0;
}
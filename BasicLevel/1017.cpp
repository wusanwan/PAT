#include<iostream>
#include<vector>
#include<cstdlib>
#include<set>
#include<string>
#include<map>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct big{
	int num[1000];
	int length;
};
int main(){
	int n;
	string a;
	cin >> a >>n;
	big b;
	b.length = a.length();
	for (int i=0; i<a.length(); i++){
		b.num[i] = a[i] - '0';
	}
	int i = 0, rest = 0, flag = 1;
	while (i < b.length){
		rest = rest * 10 + b.num[i];
		if (rest < n){
			if (b.length == 1)cout << "0";
			if (!flag)cout << "0";
		}
		else{
			int k = rest / n;
			rest = rest %  n;
			cout << k;
			flag = 0;
		}
		i++;
	}
	cout << " " << rest;
	system("pause");
	return 0;
}
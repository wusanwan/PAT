#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, a, a0, b, b0,acount=0,bcount=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a0 >> a >> b0 >> b;
		if (a == b)continue;
		if (a == a0 + b0)bcount++;
		if (b == a0 + b0)acount++;
	}
	cout << acount << " " << bcount << endl;
	system("pause");
	return 0;
}
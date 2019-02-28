#include<cstdlib>
#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
bool cmp(int a, int b){ return a > b; }
int main(){
	int n,temp;
	cin >> n;
	int a[10000] = { 0 };
	vector<int>t,result;
	for (int i = 0; i < n; i++){
		cin >> temp;
		t.push_back(temp);
		while(temp!=1){
			if (temp % 2)temp = (3 * temp + 1) / 2; 
			else temp = temp / 2;
			a[temp]++; //因为*3再/2可能会持续上涨
		}
	}
	for (int i = 0; i < n; i++){
		if (a[t[i]] == 0)result.push_back(t[i]);
	}
	sort(result.begin(), result.end(),cmp);
	for (int i = 0; i < result.size(); i++){
		if (i != 0)cout << " ";
		cout<<result[i];
	}
	system("pause");
	return 0;
}
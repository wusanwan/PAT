//1120 Friend Numbers 
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N,digit;
	scanf("%d", &N);
	set<int>sum;
	string temp;
	for (int i = 0; i < N; i++){
		int s = 0;
		cin>>temp;
		for (int j = 0; j < temp.length(); j++)
			s += temp[j] - '0';
		sum.insert(s);
	}
	printf("%d\n", sum.size());
	for (set<int>::iterator it=sum.begin(); it!=sum.end(); it++){
		if (it == sum.begin())printf("%d", *it);
		else printf(" %d", *it);
	}
	system("pause");
	return 0;
}
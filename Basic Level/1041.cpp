#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
struct stu{
	string id;
	int test, exam;
};
int main(){
	int n,m,num;
	stu list[1000];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> list[i].id >> list[i].test >> list[i].exam;
	}	
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> num;
		for (int j = 0; j < n; j++){
			if (list[j].test == num)
				cout << list[j].id << " " << list[j].exam << endl;
		}
	}
	system("pause");
	return 0;
}
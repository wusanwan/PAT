#include<iostream>
#include<set>
#include<cstdlib>
#include<string>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n;
	cin >> n;
	string s;
	set<int>friendnumber;
	for (int i = 0; i < n; i++){
		cin >> s;
		int sum = 0;
		for (int j = 0; j < s.length(); j++){
			sum += s[j] - '0';
		}
		friendnumber.insert(sum);
	}
	cout << friendnumber.size() << endl;
	for (auto it = friendnumber.begin(); it != friendnumber.end(); it++){
		if (it != friendnumber.begin())cout << " ";
		cout << *it;
	}
	system("pause");
	return 0;
}
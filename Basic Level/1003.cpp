#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#pragma warning(disable:4996)
bool judge(string a){
	int Ppos, Tpos;
	int ch[256] = { 0 };
	for (int j = 0; j < a.length(); j++){
		if (a[j] == 'P' || a[j] == 'A' || a[j] == 'T'){
			if (ch[a[j]] == 0)ch[a[j]]++;
			if (a[j] == 'P')Ppos = j;
			if (a[j] == 'T')Tpos = j;
		}
		else return false;
	}
	if (ch['P'] != 1 || ch['T'] != 1)return false;
	if ( ch['A']) return false;
	int midA = Tpos - Ppos - 1;
	int endA = a.length() - 1 - Tpos;
	int startA = Ppos;
	if (midA == 1){
		if (startA == endA)return true;
		else return false;
	}
	else{
		if (startA * 2 <= endA && (endA == 0 || endA >= midA))return true;
		else return false;
	}
}
int main(){
	int n;
	cin >> n;
	string a;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (judge(a))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}
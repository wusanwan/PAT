#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	string a, b;
	int da, db, ta = 0, tb = 0,sum,sa=0,sb=0;
	cin >> a >> da >> b >> db;
	for (int i = 0; i < a.size();i++)
		if (a[i] == da + '0')ta++;
	for (int i = 0; i < b.size(); i++)
		if (b[i] == db + '0')tb++;
	while (ta--)sa = sa * 10 + da;
	while (tb--)sb = sb * 10 + db;
	cout<<sa + sb;
	system("pause");
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, d,days,pnum=0,nnum=0;
	double e,temp;
	cin >> n;
	cin >> e;
	cin >> d;
	for (int i = 0; i < n; i++){
		cin >> days;
		int day = 0;
		for (int i = 0; i < days; i++){
			cin >> temp;
			if (temp < e)day++;
		}
		if (days>d && 2 * day>days)nnum++;
		else if (2 * day>days)pnum++;
	}
	printf("%.1lf%% %.1lf%%", (double)100 * pnum / n, (double)100 * nnum / n);
	system("pause");
	return 0;
}
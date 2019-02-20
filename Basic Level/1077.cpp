#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, m, low, high, score, teacher, count;
	cin >> n>>m;
	for (int i = 0; i < n; i++){
		double sum = 0;
		high = 0;
		low = m;
		count = n-1;
		for (int j = 0; j<n; j++){
			cin >> score;
			if (j==0)teacher=score;
			else{
				if (score >= 0 && score <= m){
					sum += score;
					if (score > high)high = score;
					if (score < low) low = score;
				}
				else count--;
			}
		}
		double aver = (sum - high - low) / (count - 2);
		int final =(teacher + aver) / 2.0 + 0.5; //×¢ÒâÊÇ³ý2.0
		cout << final << endl;
	}
	system("pause");
	return 0;
}
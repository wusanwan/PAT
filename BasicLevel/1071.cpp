#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n0, times, n1, n2, b, t;
	cin >> n0 >> times;
	for (int i = 0; i < times; i++){
		cin >> n1 >> b >> t >> n2;
		if (t>n0){//not enough
			cout << "Not enough tokens.  Total = " << n0 << "." << endl;
			continue;
		}
		if (n1 > n2 &&!b || n2 > n1 &&b){//win
			n0 += t;
			cout << "Win " << t << "!  Total = " << n0 << "." << endl;
		}
		else
		{
			n0 -= t;
			cout << "Lose " << t << ".  Total = " << n0 << "." << endl;
			if (n0 == 0){
				cout << "Game Over." << endl;
				system("pause");
				return 0;
			}
		}	
	}
	system("pause");
	return 0;
}
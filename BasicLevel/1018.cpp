#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n,wcount=0,pcount=0,winner;
	char record[2];
	int count[2][3] = { 0 };//BCJ
	cin >> n;
	char str[4] = "BCJ";
	for (int i = 0; i < n; i++){
		cin >> record[0] >> record[1];
		if (record[0] == record[1]){
			pcount++;
			continue;
		}
		else if (record[0] == 'B'&& record[1] == 'C'||record[0] == 'C'&& record[1] == 'J'||record[0] == 'J'&& record[1] == 'B'){
			wcount++;
			winner = 0;
		}
		else winner = 1;
		if (record[winner] == 'B')count[winner][0]++;
		else if (record[winner] == 'C')count[winner][1]++;
		else count[winner][2]++;
	}
	cout << wcount<<" " << pcount<<" " << n - wcount - pcount << endl;
	cout << n - wcount - pcount << " " << pcount << " " << wcount << endl;
	for(int i = 0; i < 2; i++){
		int high = 0;
		for (int j = 0; j<3; j++){
			if (count[i][j]>count[i][high])high = j;
		}
		cout << str[high];
		if (i == 0)cout << " ";
	}
	system("pause");
	return 0;
}
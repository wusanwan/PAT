#include<iostream>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int time[10] = { 0 };
	for (int i = 0; i < 10; i++){
		cin >> time[i];
	}
	for (int i = 1; i < 10; i++){
		if (time[i] >= 1){
			cout << i;
			time[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++){
		for (int j = time[i]; j>0; j--)
			cout << i;
	}
	system("pause");
	return 0;
}
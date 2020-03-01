//1038 Recover the Smallest Number 
#include<string>
#include<cstdlib>
#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin>>N;
	string str[10000];
	for (int i = 0; i < N; i++)
		cin>> str[i];
	sort(str, str + N);
	while (1){
		for (int i = 0; i < N - 1; i++){//修正
			int pos = i;
			while (str[i + 1].find(str[i]) != string::npos)i++;//pos到i-1
			for (int i = 0;)//转一轮
		}
	}
	for (int i = 1; i < N; i++)
		str[0]+= str[i];
	if (str[0][0] == '0')str[0].erase(0, 1);
	cout << str[0];
	system("pause");
	return 0;
}
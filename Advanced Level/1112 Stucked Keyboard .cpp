//1112 Stucked Keyboard 
#include<cstdlib>
#include<string>
#include<iostream>
#include<map>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N;
	string str;
	map<char, int>mp;
	cin >> N >> str;

	for (int i = 0; i < N; i++){
		int pos = i,length;
		while (i != N - 1 && str[i] == str[i + 1])i++;
		length = i - pos+1;
		if (length)

	}
	int i = 0;
	while (1){
		if (mp[++i] == 0){
			printf("%d", i);
			break;
		}
	}
	system("pause");
	return 0;
}
//1140 Look-and-say Sequence
#pragma warning(disable:4996)
#include<cstdio>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
	string str,temp;
	int N;
	cin >> str >> N;
	for (int i = 1; i < N; i++){//n th
		int count=0,pos;
		for (int j = 0; j < str.length(); j++){
			if (j == str.length() - 1 || str[j] != str[j + 1])str.insert(++j, "1");//和后一个不同
			else{//和后一个相同
				pos = j;
				while (str[j] == str[j + 1]){
					j++;
				}
				temp=to_string(j-pos+1);
				str.erase(pos + 1, j - pos);
				str.insert(pos + 1, temp);
				j = pos + 1;
			}
		}
	}
	cout << str << endl;
	system("pause");
	return 0;
}
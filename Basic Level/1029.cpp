#include<cstdio>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	string no, test;
	cin >> no;
	int ch[256] = { 0 };
	cin >> test;
	int index = 0;
	for (int i = 0; i < no.length(); i++){
		if (no[i] != test[index]){
			if (no[i]>='a'&&no[i]<='z'){
				if (ch[no[i] - 'a' + 'A'] == 0){
					putchar(no[i] - 'a' + 'A');
					ch[no[i] - 'a' + 'A'] = 1;
				}
			}
			else if (ch[no[i]] == 0){
				putchar(no[i]);
				ch[no[i]] = 1;
			}
		}
		else index++;
	}
	system("pause");
	return 0;
}
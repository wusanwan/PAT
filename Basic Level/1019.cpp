#include<iostream>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
void tostr(int num,char a[]){
	for (int i = 0; i<4; i++){
		a[i] = (num % 10) +'0';
		num = num / 10;
	}
}
bool cmp(char a, char b) { return a > b; }
int main(){
	int s, num1 = 0, num2 = 0, num3;
	cin >> s;
	char a[4];
	tostr(s,a);
	do{
		sort(a, a + 4);
		sscanf(a,"%d",&num1);
		sort(a, a + 4, cmp);
		sscanf(a, "%d", &num2);	
		if (num1 == num2){
			printf("%04d - %04d = 0000\n", num1, num1);
			break;
		}
		num3 = num2 - num1;
		printf("%04d - %04d = %04d\n", num2, num1, num3);
		tostr(num3, a);
	} while (num3 != 6174);
	system("pause");
	return 0;
}
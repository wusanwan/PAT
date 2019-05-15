//1108 Finding Average £¨20 ·Ö£©
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;
bool IsLegal(string s){
	int count=0;//count of .
	int pos; //pos of .
	float num;
	for (int i = 0; i < s.length(); i++){
		if (s[i] >= '0' && s[i]  <= '9'){
			if (count == 1 && i - pos>2)
				 return false;
		}
		else if(s[i] == '.'&&i!= 0){
			count++;
			if (count == 1)pos = i;
			if (count == 2)return false;
		}
		else if (s[i] == '-'&&i == 0);
		else {
			return false;		
		}
	}
	sscanf( s.c_str(),"%f", &num);
	if (fabs(num)<=1000)
		return true;
	else return false;
}
int main(){
	int N,count=0;
	float temp,sum=0;
	scanf("%d", &N);
	string str;
	for (int i = 0; i < N; i++){
		cin >> str;
		if (IsLegal(str)){
			sscanf(str.c_str(), "%f", &temp);
			sum += temp;
			count++;
		}
		else printf("ERROR: %s is not a legal number\n", str.c_str());
	}
	if (count == 0)printf("The average of 0 numbers is Undefined");
	else if (count == 1)printf("The average of %d number is %.2f", count, sum / count);
	else printf("The average of %d numbers is %.2f", count, sum / count);
	system("pause");
	return 0;
}
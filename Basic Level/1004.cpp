#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)
struct stu{
	string name, no;
	int grade;
};
int main(){
	int n;
	cin >> n;
	stu temp, high, low;
	cin >> temp.name >> temp.no >> temp.grade;
	high = temp;
	low = temp;
	for (int i = 1; i < n; i++){
		cin >> temp.name >> temp.no >> temp.grade;
		if (temp.grade>high.grade)high = temp;
		if (temp.grade < low.grade)low = temp;	
	}
	cout << high.name << " "<<high.no << endl;
	cout << low.name <<" "<< low.no << endl;
	system("pause");
	return 0;
}
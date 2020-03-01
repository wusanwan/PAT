//1060 Are They Equal （25 分）
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int N,size;
	double num[2];
	string a[2];
	cin>>N>>a[0]>>a[1];
	for (int i = 0; i < 2; i++){//就不能用double读，转string会丢失位数。
		sscanf(a[i].c_str(), "%lf", &num[i]);//应该用string读，转double
		if (num[i] >= 1){
			if (a[i].find(".") == string::npos)size = a[i].length();
			else{
				size = a[i].find(".");
				a[i].erase(size,1);
			}
			a[i].insert(0, "0.");			
		}
		else if (num[i] <= 1E-10)size = 0;
		else{//0.005 0.0345 0.1
			for (size = 2; a[i][size] == '0'; size++);
			size -= 2;
			if(size!=0)a[i].erase(2, size);
			size = -size;
		}
		int length = a[i].length();
		while (N > length - 2){//补零
			a[i].push_back('0');
			length++;
		}
		a[i] = a[i].substr(0, N + 2);
		a[i] += "*10^" + to_string(size);		
	}
	if (a[1] == a[0])cout << "YES " << a[0] << endl;
	else cout << "NO " << a[0] <<" "<<a[1] << endl;
	system("pause");
	return 0;
}
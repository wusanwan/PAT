//1093 Count PAT's
#pragma warning(disable:4996)
#include<cstdio>
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	string str;
	cin >> str;
	long long a = 0, t = 0, sumP=0,sumA=0;
	for (int i = str.length() - 1; i >= 0; i--){
		if (str[i] == 'T'){//当前T的数目
			t++;
		}
		else if (str[i] == 'A'){//对于当前这个A而言，T有几个就有几种AT的可能
			sumA += t;//sumA 表示当前所有AT组合的数目
		}
		else if (str[i] == 'P'){//对于当前这个P而言，AT有几个就有几种PAT的可能
			sumP += sumA;//sumP 表示当前所有PAT组合的数目
		}
		else
			continue;
	}
	printf("%lld", sumP % 1000000007);
	system("pause");
	return 0;
}

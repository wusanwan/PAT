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
		if (str[i] == 'T'){//��ǰT����Ŀ
			t++;
		}
		else if (str[i] == 'A'){//���ڵ�ǰ���A���ԣ�T�м������м���AT�Ŀ���
			sumA += t;//sumA ��ʾ��ǰ����AT��ϵ���Ŀ
		}
		else if (str[i] == 'P'){//���ڵ�ǰ���P���ԣ�AT�м������м���PAT�Ŀ���
			sumP += sumA;//sumP ��ʾ��ǰ����PAT��ϵ���Ŀ
		}
		else
			continue;
	}
	printf("%lld", sumP % 1000000007);
	system("pause");
	return 0;
}

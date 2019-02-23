#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int main(){
	int n, m, temp,pnum=0,inum=0;
	cin >> n >> m;
	int no[10000] = { 0 };
	for (int i = 0; i < m; i++){
		cin >> temp;
		no[temp] = 1;
	}
	for (int i = 0; i < n; i++){
		string name;
		int item,flag=1;
		cin >> name >> item;
		for (int j = 0; j < item; j++){
			cin >> temp;
			if (no[temp] == 1){
				if (flag){
					printf("%s: %04d",name.c_str(),temp);
					flag = 0;
					pnum++;
					inum++;
				}
				else{
					printf(" %04d",temp);
					inum++;
				}
			}
		}
		if (!flag)printf("\n");
	}
	printf("%d %d",pnum,inum);
	system("pause");
	return 0;
}
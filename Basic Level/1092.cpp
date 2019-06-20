#pragma warning(disable:4996)
#include<string>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
struct mooncake{
	int no; int sum=0;
};
bool cmp(mooncake a, mooncake b){ 
	if(a.sum!=b.sum)
		return a.sum > b.sum; 
	else return a.no < b.no;
}
int main(){
	int N,M,temp;
	cin >> N>>M;
	mooncake mooncake1[1001];
	for (int i = 0; i < M; i++){
		for (int j = 1; j <= N; j++){
			cin >> temp;
			mooncake1[j].sum += temp;
			mooncake1[j].no = j;
		}
	}
	sort(mooncake1+1, mooncake1+N+1,cmp);
	cout << mooncake1[1].sum << endl;
	int k = 1;
	cout << mooncake1[1].no;
	while (mooncake1[k + 1].sum == mooncake1[k].sum && k +1<= N){
		k++;
		cout << " " << mooncake1[k].no;
	}
	system("pause");
	return 0;
}
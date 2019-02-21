#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
struct mooncake{
	double weight,price,per;
};
bool cmp(mooncake a, mooncake b){
	return a.per > b.per;
}
int main(){
	int n,d,j=0;
	double sum = 0;
	cin >> n>>d;
	mooncake list[1000];
	for (int i = 0; i < n; i++)
		cin >> list[i].weight;
	for (int i = 0; i < n; i++){
		cin >> list[i].price;
		list[i].per = list[i].price / list[i].weight;
	}
	sort(list, list + n, cmp);
	while (d&&j!=n){
		if (list[j].weight>d){
			sum += d*list[j].per;
			d = 0;
		}
		else{
			sum += list[j].price;
			d -= list[j].weight;
		}
		j++;
	}
	printf("%.2f",sum);
	system("pause");
	return 0;
}
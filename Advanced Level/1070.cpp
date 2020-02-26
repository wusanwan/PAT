//1070 Mooncake
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct mooncake{
	double amount,price, perprice;
};
bool cmp(mooncake a, mooncake b){ return a.perprice > b.perprice; }
int main(){
	double maxpro=0;
	int N, D,i=0;
	scanf("%d %d", &N, &D);
	mooncake list[1000];
	for (int i = 0; i < N; i++)
		scanf("%lf", &list[i].amount);
	for (int i = 0; i < N; i++){
		scanf("%lf", &list[i].price);
		list[i].perprice = list[i].price / list[i].amount;
	}
	sort(list, list + N, cmp);
	while (D>0){
		if (list[i].amount <= D){
			maxpro += list[i].price;
			D -= list[i].amount;
		}
		else{
			maxpro += D*list[i].perprice;
			break;
		}
		i++;
	}
	printf("%.2lf", maxpro);
	system("pause");
	return 0;
}

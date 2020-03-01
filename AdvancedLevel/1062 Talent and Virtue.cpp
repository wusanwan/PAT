//1062 Talent and Virtue
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
struct person{
	int ID,virtue, talent, total, result;
};
bool cmp(person a, person b){
	if (a.result != b.result)return a.result < b.result;
	else if(a.total!=b.total)return a.total>b.total;
	else if (a.virtue != b.virtue)return a.virtue> b.virtue;
	else return a.ID < b.ID;
}
int main(){
	int ID,N, L, H,virtue,talent,n=0;
	scanf("%d %d %d", &N, &L,&H);
	person list[10000];
	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &ID,&virtue,&talent);
		if (virtue<L || talent<L)continue;
		else if (virtue >= H &&talent >= H)list[n].result = 0;
		else if (virtue >= H)list[n].result = 1;
		else if (virtue <= H &&talent <= H && virtue >= talent)list[n].result = 2;
		else list[n].result =3;
		list[n].ID = ID;
		list[n].virtue = virtue;
		list[n].talent = talent;
		list[n].total = list[n].virtue + list[n].talent;
		n++;
	}
	sort(list, list + n, cmp);
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n",list[i].ID, list[i].virtue, list[i].talent);
	system("pause");
	return 0;
}
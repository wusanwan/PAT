//1109 Group Photo
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
#pragma warning(disable:4996)
struct person{
	char name[12];
	int height;
};
bool cmp(person a, person b){//
	if (a.height == b.height && strcmp(b.name, a.name)>0)return true;
	else return a.height > b.height;
}
int main(){
	int N, K,first,last,count=0;
	scanf("%d %d", &N, &K);
	person list[10100];
	int pos[10100];
	for (int i = 0; i < N; i++)
		scanf("%s %d", &list[i].name, &list[i].height);
	sort(list, list + N, cmp);
	first = round(N / K);
	last = N - first * (K-1);
	for (int i= 0; i < K; i++){//对于每行
		int center,rowK;
		if (!i)rowK = last;//选择队列长度
		else rowK = first;
		center = rowK / 2 ; //选择队列中心
		for (int j = 0; j < rowK; j++){//安排位置顺序
			center += pow(-1, j)*j;
			pos[center] = j;
		}
		for (int j = 0; j < rowK; j++){//输出安排
			if (j == rowK - 1)printf("%s", list[pos[j] + count].name);
			else printf("%s ",list[pos[j]+count].name);
		}
		printf("\n");
		count += rowK;
	}
	system("pause");
	return 0;
}
//1012 The Best Rank （25 分）
#pragma warning (disable:4996)
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
using namespace std;
struct student{
	int ID;
	float grade[4];//ACME
	int rank[4];//ACME;
};
bool cmpA(student a, student b){
	return a.grade[0] > b.grade[0];
}
bool cmpC(student a, student b){
	return a.grade[1] > b.grade[1];
}
bool cmpM(student a, student b){
	return a.grade[2] > b.grade[2];
}
bool cmpE(student a, student b){
	return a.grade[3] > b.grade[3];
}
int main(){
	int N, M;
	student list1[2000];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){//list1
		scanf("%d %f %f %f", &list1[i].ID, &list1[i].grade[1], &list1[i].grade[2], &list1[i] .grade[3]);
		list1[i].grade[0] = (list1[i].grade[1] + list1[i].grade[2] + list1[i].grade[3]) / 3;
	}
	//A
	sort(list1, list1 + N, cmpA);
	for (int i = 0; i < N; i++){
		list1[i].rank[0] = i + 1;
		if (i != 0 && list1[i].grade[0] == list1[i - 1].grade[0])list1[i].rank[0] = list1[i - 1].rank[0];
	}
	//C
	sort(list1, list1 + N, cmpC);
	for (int i = 0; i < N; i++){
		list1[i].rank[1] = i + 1;
		if (i != 0 && list1[i].grade[1] == list1[i - 1].grade[1])list1[i].rank[1] = list1[i - 1].rank[1];
	}
	//M
	sort(list1, list1 + N, cmpM);
	for (int i = 0; i < N; i++){
		list1[i].rank[2] = i + 1;
		if (i != 0 && list1[i].grade[2] == list1[i - 1].grade[2])list1[i].rank[2] = list1[i - 1].rank[2];
	}
	//E
	sort(list1, list1 + N, cmpE);
	for (int i = 0; i < N; i++){
		list1[i].rank[3] = i + 1;
		if (i != 0 && list1[i].grade[3] == list1[i - 1].grade[3])list1[i].rank[3] = list1[i - 1].rank[3];
	}
	//output
	for (int i = 0; i < M;i++){
		char str[5] = "ACME";
		int query,index=0,flag=0;
		scanf("%d", &query);
		for (; index < N &&!flag; index++){//假设提问序号有序
			if (list1[index].ID == query){//找到的
				int course = 0;
				for (int j = 1; j < 4; j++){
					if (list1[index].rank[j] < list1[index].rank[course])course = j;
				}
				printf("%d %c\n", list1[index].rank[course], str[course]);
				flag = 1;
			}
		}
		if (!flag)printf("N/A\n");
	}
	system("pause");
	return 0;
}
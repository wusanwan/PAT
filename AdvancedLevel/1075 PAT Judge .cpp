//1075 PAT Judge 
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
struct person{
	int id = -1, full = 0, sum = 0;
	int score[5];
};
bool cmp(person a, person b){
	if (a.sum != b.sum)return a.sum > b.sum;
	else if (a.full!=b.full)return a.full>b.full;
	else return a.id < b.id;
}
int main(){
	int fullmark[5];
	int N, K, M, id, index, score;
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 0; i < K; i++)
		scanf("%d", &fullmark[i]);
	person list[10000];
	for (int i = 0; i < N; i++)//³É¼¨³õÊ¼»¯
		fill(list[i].score, list[i].score + K, -1);
	for (int i = 0; i < M; i++){
		scanf("%d %d %d", &id, &index, &score);
		if (score == -1)score = 0;
		if (score>list[id - 1].score[index - 1]){
			if (list[id - 1].score[index - 1]!=-1)list[id - 1].sum -= list[id - 1].score[index - 1];
			list[id - 1].score[index - 1] = score;
			list[id - 1].sum += score;
			list[id - 1].id = id;
			if (score == fullmark[index - 1])list[id - 1].full++;
		}
	}
	sort(list, list + N, cmp);
	int rank = 0;
	for (int i = 0; i < N; i++){
		if (list[i].sum <= 0)break;
		if (!i||list[i].sum != list[i - 1].sum)rank=i+1;
		printf("%d %05d %d", rank,list[i].id,list[i].sum);
		for (int j = 0; j < K; j++){
			if (list[i].score[j] == -1)printf(" -");
			else printf(" %d", list[i].score[j]);
		}
		printf("\n");
	}	
	system("pause");
	return 0;
}
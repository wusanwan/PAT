//1025 PAT Ranking
#pragma warning(disable:4996)
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
struct student{
	char number[14];
	int score;
	int location;
	int finalrank;
	int localrank;
};
bool cmp(student a, student b){
	if (a.score == b.score)return strcmp(a.number, b.number)<0;
	else return a.score > b.score;
}
int main(){
	int N, K, index = 0;
	student list[30000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){//each ranklist
		scanf("%d", &K);
		for (int j = 0; j < K; j++){//读入数据
			scanf("%s %d", &list[index + j].number, &list[index + j].score);
			list[index + j].location = i + 1;
		}
		sort(list+index, list+index + K, cmp);//不要写成list[index]了！
		for (int j = 0; j < K; j++){//内部排序
			list[index + j].localrank = j + 1;
			if (j != 0 && list[index + j - 1].score == list[index + j].score)list[index + j].localrank = list[index + j - 1].localrank;
		}
		index += K;
	}
	sort(list,list+index, cmp);//总体排序
	printf("%d\n", index);
	for (int i = 0; i < index; i++){
		list[i].finalrank = i + 1;
		if (i != 0 && list[i - 1].score == list[i].score)list[i].finalrank = list[i - 1].finalrank;
		printf("%s %d %d %d\n", list[i].number, list[i].finalrank, list[i].location, list[i].localrank);
	}
	system("pause");
	return 0;
}
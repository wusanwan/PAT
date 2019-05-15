//1028 List Sorting
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
using namespace std;
struct student{
	char str[3][12];
};
int C=-1;//全局变量,千万不能在int main里重新定义了
bool cmp(student a, student b){//这里字符串相等的时候用strcmp
	if (strcmp(a.str[C-1],b.str[C-1])==0)return strcmp(a.str[0], b.str[0])< 0;
	else return strcmp(a.str[C-1], b.str[C-1]) < 0;
}
int main(){
	int N;
	student list[100000];
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++){
		scanf("%s %s %s", &list[i].str[0], &list[i].str[1], &list[i].str[2]);
	}
	sort(list, list + N, cmp);
	for (int i = 0; i < N;i++)
		printf("%s %s %s\n", list[i].str[0], list[i].str[1], list[i].str[2]);
	system("pause");
	return 0;
}
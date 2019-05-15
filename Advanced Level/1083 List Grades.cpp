//1083 List Grades
#pragma warning(disable:4996)
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct student{
	char name[12];
	char ID[12];
	int grade;
};
bool cmp(student a, student b){
	return a.grade > b.grade;
}
int main(){
	int N;
	scanf("%d", &N);
	student stu[10000];
	for (int i = 0; i < N; i++)
		scanf("%s %s %d", &stu[i].name, &stu[i].ID, &stu[i].grade);
	int min, max, pos, length = 0;
	scanf("%d %d", &min, &max);
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++){//确定区间
		if (stu[i].grade >= min && stu[i].grade <= max){
			printf("%s %s\n", stu[i].name, stu[i].ID);
			length++;
		}
		else if (stu[i].grade<min)break;
	}
	if (length == 0)printf("NONE\n");
	system("pause");
	return 0;
}
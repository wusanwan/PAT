//1036 Boys vs Girls （25 分）
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
struct student{
	char name[11];
	char gender;
	char ID[11];
	int grade;
};
int main(){
	int N,boy=1000,girl=1001;
	student stu[1002];
	scanf("%d", &N);
	//设置了两个假人
	stu[1000].gender = 'M';
	stu[1000].grade = 101;
	stu[1001].gender = 'F';
	stu[1001].grade = -1;
	for (int i = 0; i < N; i++){
		scanf("%s %c %s %d", &stu[i].name, &stu[i].gender, &stu[i].ID, &stu[i].grade);
		if (stu[i].gender == 'M'&&stu[i].grade < stu[boy].grade)boy = i;
		if (stu[i].gender == 'F'&&stu[i].grade > stu[girl].grade)girl = i;
	}
	//output
	if (girl == 1001)printf("Absent\n");
	else printf("%s %s\n", stu[girl].name, stu[girl].ID);
	if(boy == 1000)printf("Absent\n");
	else printf("%s %s\n", stu[boy].name, stu[boy].ID);
	if (girl == 1001 || boy == 1000)printf("NA");
	else printf("%d", stu[girl].grade - stu[boy].grade);
	system("pause");
	return 0;
}
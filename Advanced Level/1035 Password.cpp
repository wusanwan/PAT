//1035 Password £¨20 ·Ö£©
#pragma warning(disable:4996)
#include<cstdio>
#include<string.h>
#include<cstdlib>
struct Team{
	char name[12];
	char password[12];
	bool flag = false;
};
int main(){
	int N,count=0;
	Team list[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s %s", &list[i].name, &list[i].password);
		for (int j = 0; j < strlen(list[i].password); j++){
			switch (list[i].password[j]){
			case'1':
				list[i].password[j] = '@';
				list[i].flag = true;
				break;
			case'0':
				list[i].password[j] = '%';
				list[i].flag = true;
				break;
			case'l':
				list[i].password[j] = 'L';
				list[i].flag = true;
				break; 
			case'O':
				list[i].password[j] = 'o';
				list[i].flag = true;
				break;
			default:
				break;
			}
		}
		if (list[i].flag)count++;
	}
	if (count == 0 && N ==1)
		printf("There is %d account and no account is modified", N);
	else if(count==0)
		printf("There are %d accounts and no account is modified", N);
	else{
		printf("%d\n", count);
		for (int i = 0; i < N; i++){
			if (list[i].flag)printf("%s %s\n", list[i].name, list[i].password);
		}
	}
	system("pause");
	return 0;
}
//1148werewolf
#pragma warning(disable:4996)
#include<stdlib.h>
#include<cstdio>
#include<cmath>
bool WereWolf(int word[], int N,int a, int b){//假设a,b狼人。矛盾即为说谎，判断标准1，说谎的人有一个为狼人 2.2个说谎的人liarwolf = false;
	int  liars = 0, liarwolf = 0;
	for (int i = 0; i < N; i++){//说1是0，说0是1,这里其实word[i]
		if ((abs(word[i]) == a+1 && word[i]>0 || abs(word[i]) == b+1 && word[i] > 0) || (abs(word[i]) != a+1 && abs(word[i]) != b+1 && word[i]<0)){//liar
			liars++;
			if (i == a || i == b)liarwolf++;
		}
		if (liars > 2 && liarwolf>1 )return false;
	}
	if (liars == 2 && liarwolf){
		printf("%d %d", a+1, b+1);
		return true;
	}
	else return false;
}
int main(){
	int N,flag=0;
	scanf("%d", &N);
	int word[100];
	for (int i = 0; i < N; i++)scanf("%d", &word[i]);
	for (int i = 0; i < N - 1 && !flag; i++) //i,j位为狼人
		for (int j = i + 1; j < N && !flag; j++)
			if (WereWolf(word,N, i, j))flag = 1;
	if (!flag)printf("No Solution");
	system("pause");
	return 0;
}
//1148werewolf
#pragma warning(disable:4996)
#include<stdlib.h>
#include<cstdio>
#include<cmath>
bool WereWolf(int word[], int N,int a, int b){//����a,b���ˡ�ì�ܼ�Ϊ˵�ѣ��жϱ�׼1��˵�ѵ�����һ��Ϊ���� 2.2��˵�ѵ���liarwolf = false;
	int  liars = 0, liarwolf = 0;
	for (int i = 0; i < N; i++){//˵1��0��˵0��1,������ʵword[i]
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
	for (int i = 0; i < N - 1 && !flag; i++) //i,jλΪ����
		for (int j = i + 1; j < N && !flag; j++)
			if (WereWolf(word,N, i, j))flag = 1;
	if (!flag)printf("No Solution");
	system("pause");
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int isprime
int findpos(char list[][4],int N,char one[4] ){
	for (int i = 0; i < N; i++){
		if(strcmp(list[i],one)==0)
			if (!i)return 1;
			else if (isprime(i)) return 2; //minion
			else return 3;// chocolate
		else return 4;// are you kidding?
	}
}
int main(){
	int N, K;
	scanf_s("%d", &N);
	char award[N][4];
	for (int i = 0; i < N; i++){
		scanf_s("%s", &award[i]);
	}
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++){
		char tempquery[4];
		scanf_s("%s", &tempquery);
		for (int i=0)
		
	}
	system("pause");
	return 0;
}
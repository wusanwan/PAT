//1041 Be Unique
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N,flag=1;
	scanf("%d", &N);
	int list[10000], input[100000];
	fill(list, list + 10000, 0);
	for (int i = 0; i < N; i++){
		scanf("%d", &input[i]);
		list[input[i] - 1]++;
	}
	for (int i = 0; i < N; i++){
		if (list[input[i] - 1] == 1){
			flag = 0;
			printf("%d", input[i]);
			break;
		}
	}
	if (flag)printf("None");
	system("pause");
	return 0;
}
//1144 The Missing Number 
#include<cstdio>
#include<cstdlib>
#include<map>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int N,temp;
	scanf("%d", &N);
	map<int, int>mp;
	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		mp[temp]++;
	}
	int i = 0;
	while (1){
		if (mp[++i] == 0){
			printf("%d", i);
			break;
		}
	}
	system("pause");
	return 0;
}
//1101 Quick Sort
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main(){
	int N,high=0;
	scanf("%d", &N);
	vector<int>a(N),lowest(N),result;
	for (int i = 0; i < N; i++)//input
		scanf("%d", &a[i]);
	for (int i = N-1; i>=0; i--){
		if (i == N - 1||a[i] < a[lowest[i + 1]])lowest[i] = i;
		else lowest[i] = lowest[i + 1];
	}
	for (int i = 0; i < N; i++){
		if (a[high] <= a[i] && a[i] <= a[lowest[i]])result.push_back(a[i]);
		if (a[high] <= a[i])high = i;	
	}
	printf("%d\n", result.size());//output
	for (int i = 0; i < result.size(); i++){
		printf("%d", result[i]);
		if (i != result.size() - 1)printf(" ");
	}
	printf("\n");
	system("pause");
	return 0;
}
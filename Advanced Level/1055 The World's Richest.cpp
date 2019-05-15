//1055 The World's Richest
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
struct person{
	char name[9];
	int age;
	int worth;
};
bool cmpage(person a, person b){
	return a.age < b.age;
}
int main(){
	int N,M;
	scanf("%d %d", &N, &M);
	person list[10000];
	for (int i = 0; i < N; i++){
		scanf("%s %d %d", &list[i].name, &list[i].age, &list[i].worth);
	}
	sort(list, list + N, cmpage);//初始顺序按年龄排
	for (int i = 0; i < M; i++){
		int num, amin, amax, pos, length=0;
		scanf("%d %d %d", &num, &amin, &amax);
		int start=0, end=N-1;
		while(start<=end){//找初始位置和区间长度//二分法找？
			int mid = (start + end) / 2;
			if (list[mid].age < amin)start = mid + 1;
			else if (list[mid].age>amax)end = mid - 1;
			else if (list[mid].age>= amin && list[mid].age<=amax){
				length++;
				pos = mid;
				while (list[++pos].age >= amin && list[pos].age <= amax)length++;
				pos = mid;
				while (list[--pos].age >= amin && list[pos].age <= amax)length++;
				pos++;
				break;
			}
		}
		printf("Case #%d:\n", i + 1);
		if (length == 0)printf("None\n");
		if (length < num)num = length;
		map < int, int> isordered;	
		for (int j = 0; j < num; j++){//length个数里找num个最大的
			int highest = -1;
			int highestmoney = -111111;
			for (int k =0; k < length; k++){
				if (isordered[pos + k] == 1)continue;
				else if (highestmoney<list[pos + k].worth){
					highest = k;
					highestmoney = list[pos + k].worth;
				}
				else if (list[pos + highest].worth == list[pos + k].worth&&list[pos + highest].age > list[pos + k].age)highest = k;
				else if (list[pos + highest].worth == list[pos + k].worth&&list[pos + highest].age == list[pos + k].age && strcmp(list[pos + k].name, list[pos + highest].name) < 0)highest = k;
			}
			isordered[pos + highest] = 1;		
			printf("%s %d %d\n", list[pos + highest].name, list[pos + highest].age, list[pos + highest].worth);
		}
	}
	system("pause");
	return 0;
}
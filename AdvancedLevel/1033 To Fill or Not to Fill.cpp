//1033 To Fill or Not to Fill
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
struct station{
	float price, distance;
};
bool cmp(station a, station b) { return a.price < b.price; }
int main(){
	int cmax, d, davg, n,start,index,max;
	station list[500];
	float x,sum=0;
	for (int i = 0; i < n; i++)
		scanf("%f %d", &list[i].price, &list[i].distance);
	sort(list, list + n, cmp);
	for (start = 0; start < n;start++)
		if (list[start].distance == 0)break;
		max = davg*cmax;
	while (1){
		for (int index = 0; index < n; index++){
			if (list[index].distance>list[start].distance && (list[index].distance - list[start].distance) < max){
				sum += (list[index].distance - list[start].distance) / davg*list[start].price;
			}

		}
	}
	system("pause");
	return 0;
}
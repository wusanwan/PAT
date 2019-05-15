//1129 Recommendation System
#include<cstdio>
#include<set>
#include<cstdlib>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct item{
	int ID, times = 0;
};
struct cmp{
	item a, item b){
	if (a.times != b.times)return a.times > b.times;
	else return a.ID < b.ID;
}
int main(){
	int query, items;
	scanf("%d", &query, &items);
	set<item,cmp>result;
	for£¨int i = 0; i < query;i++)

	system("pause");
	return 0;
}
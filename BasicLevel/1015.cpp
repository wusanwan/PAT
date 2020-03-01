#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#pragma warning(disable:4996)
struct stu{
	int id, dgrade, cgrade, tgrade, classno;
};
bool cmp(stu a, stu b){
	if (a.classno != b.classno)return a.classno < b.classno;
	else if(a.tgrade!=b.tgrade)return a.tgrade>b.tgrade;
	else if(a.dgrade != b.dgrade)return a.dgrade>b.dgrade;
	else return a.id < b.id;
}
int main(){
	int N, L, H, id, dgrade, cgrade;
	scanf("%d %d %d",&N,&L,&H);
	vector<stu>list;
	stu temp;
	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &id, &dgrade, &cgrade);
		if (dgrade < L||cgrade < L)continue;
		else{
			temp.id = id;
			temp.dgrade = dgrade;
			temp.cgrade = cgrade;
			temp.tgrade = dgrade + cgrade;
		}
		if (dgrade >= H && cgrade >= H)temp.classno = 1;
		else if (dgrade >= H)temp.classno = 2;
		else if (dgrade >= cgrade)temp.classno = 3;
		else temp.classno = 4;
		list.push_back(temp);
	}
	sort(list.begin(), list.end(), cmp);
	printf("%d\n", list.size());
	for (int i = 0; i < list.size(); i++){
		printf("%d %d %d\n", list[i].id, list[i].dgrade, list[i].cgrade);
	}
	system("pause");
	return 0;
}
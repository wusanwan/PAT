//1121 Damn Single
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<set>
#include<map>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main(){
	map<int, int>mp;
	int couples, guest, temp,x,y;
	scanf("%d", &couples);
	for (int i = 0; i < couples; i++){//�洢����
		scanf("%d %d", &x, &y);
		mp[x] = y;
		mp[y] = x;
	}
	scanf("%d", &guest);
	vector<int>judge;
	set<int>dog;
	for (int i = 0; i < guest; i++){
		scanf("%d", &temp);
		judge.push_back(temp);
	}
	for (auto it = judge.begin(); it != judge.end(); it++){
		if (mp[*it] != 0 && find(judge.begin(), judge.end(), mp[*it]) == judge.end())//�а��µ��ǰ���û��
			dog.insert(*it);
		if (mp[*it] == 0)dog.insert(*it);//�ް���
	}
	printf("%d\n", dog.size());
	for (auto it = dog.begin(); it != dog.end(); it++){
		if (it != dog.begin())printf(" ");
		printf("%d", *it);
	}
	system("pause");
	return 0;
}
//1137 Final Grading （25 分）
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<cmath>
#include<utility>					//注意
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
struct stu{
	int gp = -1, gmid = -1, gfinal = -1, gtotal = -1;
};
bool cmp(pair< string,stu> a ,pair< string,stu> b){ //注意
	if (a.second.gtotal == b.second.gtotal)return a.first < b.first;
	else return a.second.gtotal > b.second.gtotal;
}
int main(){
	int P,M,N,score;
	cin >> P >> M >> N;
	string id;
	map<string, stu>mp;
	for (int i = 0; i < P; i++){// online programming assignments
		cin >> id >>score;
		if (score >= 200)mp[id].gp = score;
	}
	for (int i = 0; i < M; i++){// mid-test
		cin >> id >> score;
		if (mp[id].gp!=-1)mp[id].gmid = score;
	}
	for (int i = 0; i < N; i++){// final-test and calculate the total grade
		cin >> id >> score;
		if (mp[id].gp != -1){
			mp[id].gfinal = score;
			if (mp[id].gmid>mp[id].gfinal)mp[id].gtotal = round(0.4*mp[id].gmid + 0.6*mp[id].gfinal);
			else mp[id].gtotal = mp[id].gfinal;
		}
	}
	vector<pair<string,stu> >rank(mp.begin(), mp.end());//将值转存入pair用vector进行排序，注意！
	sort(rank.begin(), rank.end(), cmp);
	for (int i = 0; i < rank.size();i++){//这里就不要用迭代器写了
		if (rank[i].second.gtotal<60)break;
		cout <<rank[i].first << " " << rank[i].second.gp << " " << rank[i].second.gmid << " " << rank[i].second.gfinal << " " << rank[i].second.gtotal << endl;
	}	
	system("pause");
	return 0;
}
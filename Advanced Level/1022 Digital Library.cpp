//1022 Digital Library
//1137 Final Grading ��25 �֣�
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<cmath>
#include<utility>					//ע��
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
struct book{
	int gp = -1, gmid = -1, gfinal = -1, gtotal = -1;
};
int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){// book information
		cin >> id >> score;
		if (score >= 200)mp[id].gp = score;
	}
	for (int i = 0; i < M; i++){// mid-test
		cin >> id >> score;
		if (mp[id].gp != -1)mp[id].gmid = score;
	}
	for (int i = 0; i < N; i++){// final-test and calculate the total grade
		cin >> id >> score;
		if (mp[id].gp != -1){
			mp[id].gfinal = score;
			if (mp[id].gmid>mp[id].gfinal)mp[id].gtotal = round(0.4*mp[id].gmid + 0.6*mp[id].gfinal);
			else mp[id].gtotal = mp[id].gfinal;
		}
	}
	vector<pair<string, stu> >rank(mp.begin(), mp.end());//��ֵת����pair��vector��������ע�⣡
	sort(rank.begin(), rank.end(), cmp);
	for (int i = 0; i < rank.size(); i++){//����Ͳ�Ҫ�õ�����д��
		if (rank[i].second.gtotal<60)break;
		cout << rank[i].first << " " << rank[i].second.gp << " " << rank[i].second.gmid << " " << rank[i].second.gfinal << " " << rank[i].second.gtotal << endl;
	}
	system("pause");
	return 0;
}
//1121 Damn Single
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
//�����int�棬mapĬ��Ϊ1��Ҫ����0Ҳ���ˣ�
int main(){
	map<string, string>mp;
	int couples, guest;
	string x, y;
	cin>>couples;
	for (int i = 0; i < couples; i++){//�洢����
		cin >> x >> y;
		mp[x] = y;
		mp[y] = x;
	}
	cin>>guest;
	vector<string>judge;
	int arrive[100000] = { 0 };
	set<string>dog;
	string temp;
	int tempint;
	for (int i = 0; i < guest; i++){//�������
		cin >> temp;
		judge.push_back(temp);//��������嵥
		tempint=stoi(temp);
		arrive[tempint] = 1;//����ǩ����
	}
	for (auto it = judge.begin(); it != judge.end(); it++){//�жϿ������ް���
		if (mp[*it] == "")dog.insert(*it);//����
		else{//�а��µ�û��
			int spouse = stoi(mp[*it]);
			if (!arrive[spouse])//�а��µ��ǰ���û�����ް���
				dog.insert(*it);
		}
	}
	cout<<dog.size()<<endl;
	for (auto it = dog.begin(); it != dog.end(); it++){
		if (it != dog.begin())cout<<" ";
		cout<<*it;
	}
	system("pause");
	return 0;
}
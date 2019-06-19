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
//如果用int存，map默认为1，要避免0也来了？
int main(){
	map<string, string>mp;
	int couples, guest;
	string x, y;
	cin>>couples;
	for (int i = 0; i < couples; i++){//存储情侣
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
	for (int i = 0; i < guest; i++){//读入客人
		cin >> temp;
		judge.push_back(temp);//加入客人清单
		tempint=stoi(temp);
		arrive[tempint] = 1;//加入签到表
	}
	for (auto it = judge.begin(); it != judge.end(); it++){//判断客人有无伴侣
		if (mp[*it] == "")dog.insert(*it);//单身
		else{//有伴侣但没来
			int spouse = stoi(mp[*it]);
			if (!arrive[spouse])//有伴侣但是伴侣没来或无伴侣
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
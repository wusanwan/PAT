#include<string>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
int main(){
	int M, N, S;
	cin >> M >> N >> S;
	string str;
	vector<string>list;
	map<string, int>mp;
	for (int i = 0; i < M; i++){
		cin >> str;
		list.push_back(str);
	}
	int distance = N-1;
	for (int i = S-1; i < list.size(); i++){
		if (mp[list[i]] == 1)continue;
		else distance++;
		if (distance == N){
			cout << list[i]<<endl;
			mp[list[i]] = 1;
			distance = 0;
		}
	}
	if (S>M)cout << "Keep going...";
	system("pause");
	return 0;
}
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct poly{
	int value;
	int exp;
};
void add(vector<poly>v1, vector<poly>v2){//类似于归并过程，注意相加后为0的项不输出
	int i = 0, j = 0;
	vector<poly>result;
	while (i<v1.size() && j<v2.size()){
		if (v1[i].exp>v2[j].exp){
			result.push_back(v1[i]);
			i++;
		}
		else if (v2[j].exp>v1[i].exp){
			result.push_back(v2[j]);
			j++;
		}
		else {
			poly temp;
			temp.value = v1[i].value + v2[j].value;
			if (temp.value != 0){
				temp.exp = v1[i].exp;
				result.push_back(temp);
			}
			i++; j++;
		}
	}
	while (i<v1.size()){
		result.push_back(v1[i]);
		i++;
	}
	while (j<v2.size()){
		result.push_back(v2[j]);
		j++;
	}
	for (int k = 0; k<result.size(); k++){
		if (k)cout << " ";
		cout << result[k].value << " " << result[k].exp;
	}
	if (result.size() == 0)cout << "0 0";
}
void multiply(vector<poly>v1, vector<poly>v2){
	map<int,int>result;				//exp,value
	for (int i = 0; i<v1.size(); i++){
		for (int j = 0; j<v2.size(); j++){
			int exp = v1[i].exp + v2[j].exp;
			int value = v1[i].value*v2[j].value;
			result[exp] += value;
		}
	}
	int flag = 0;
	map<int, int>::reverse_iterator it;
	for (it=result.rbegin(); it!= result.rend(); it++){
		if (it->second != 0){
			if (flag)cout << " ";
			cout << it->second << " " << it->first;
			flag = 1;
		}
	}
	if (!flag)cout << "0 0";
	cout << "\n";
}
int main(){
	vector<poly> v1, v2;
	int n;
	poly temp;
	cin >> n;
	for (int i = 0; i<n; i++){//v1
		cin >> temp.value >> temp.exp;
		v1.push_back(temp);
	}
	cin >> n;
	for (int i = 0; i<n; i++){//v2
		cin >> temp.value >> temp.exp;
		v2.push_back(temp);
	}
	multiply(v1, v2);
	add(v1, v2);
	system("pause");
	return 0;
}
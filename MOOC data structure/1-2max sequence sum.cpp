#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main(){
	int N, temp,length,index=0;
	cin >> N;
	vector<int>list;
	int max = 0, now = 0, flag = 1;
	for (int i = 0; i < N; i++){
		cin >> temp; 
		list.push_back(temp);
		if (flag&&temp>=0)flag = 0;
	}
	int start = list[0], first, last = list[0];
	if (flag){//negative
		cout << max << " " << list[0] << " " <<list[list.size()-1];
	}
	else{
		for (int i = 0; i < N; i++){
			now += list[i];
			if (now>max || now == max &&max == 0){
				max = now;
				last = list[i];
				first = start;
			}
			else if (now < 0){
				if(i+1<N)start = list[i+1];
				now = 0;
			}
		}
		cout << max << " " << first << " " << last;
	}
	system("pause");
	return 0;
}
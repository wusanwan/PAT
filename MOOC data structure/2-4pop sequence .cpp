#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

bool IsPopSequence(vector<int>temp,int M,int N){
	int in = 1;//进到几号了（进是有序的，出是无序的）
	int out = 0;//出了几个了
	stack<int>sim;
	for(in=1;in<=N;in++){//判定序列首位是否可出栈
		sim.push(in);
		if (sim.size() > M)return false;
		while (sim.size()> 0 &&temp[out]==sim.top()){//栈不空,且一样时出
			sim.pop();
			out++;
		}
		if (out<N && in > temp[out])return false;//提早结束
	}
	if(N==out)return true;
	else return false;
}
int main(){
	int M, N, K;
	cin >> M >> N >> K;		//原始数列是到N为止
	for (int i = 0; i < K; i++){
		vector<int>test;
		int t;
		for (int i = 0; i < N; i++){
			cin >> t;
			test.push_back(t);
		}		
		if (IsPopSequence(test,M,N))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
} 
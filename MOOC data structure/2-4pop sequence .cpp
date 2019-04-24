#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

bool IsPopSequence(vector<int>temp,int M,int N){
	int in = 1;//���������ˣ���������ģ���������ģ�
	int out = 0;//���˼�����
	stack<int>sim;
	for(in=1;in<=N;in++){//�ж�������λ�Ƿ�ɳ�ջ
		sim.push(in);
		if (sim.size() > M)return false;
		while (sim.size()> 0 &&temp[out]==sim.top()){//ջ����,��һ��ʱ��
			sim.pop();
			out++;
		}
		if (out<N && in > temp[out])return false;//�������
	}
	if(N==out)return true;
	else return false;
}
int main(){
	int M, N, K;
	cin >> M >> N >> K;		//ԭʼ�����ǵ�NΪֹ
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
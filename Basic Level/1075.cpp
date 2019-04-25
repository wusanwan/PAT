#include<stdio.h>
#pragma warning(disable:4996)
#include<vector>
#include<iostream>
using namespace std;
struct node{
	int address;
	int data;
	int next;
};
int main(){
	int hash[100000][2] = { -1 };//data,next
	int N, K, firstaddress;
	cin >> firstaddress >> N >> K;
	for (int i = 0; i < N; i++){//利用数组的索引达到O(1)的搜索速度
		int address;
		cin >> address;
		cin >> hash[address][0] >> hash[address][1];
	}
	int address = firstaddress;
	vector<node>negative;
	vector<node>lessK;
	vector<node>greaterK;
	while (1){	//根据实际的顺序，打包分类丢vector
		node temp;
		temp.address = address;
		temp.data = hash[address][0];
		temp.next = hash[address][1];
		if (temp.data<0)negative.push_back(temp);
		else if (temp.data <= K)lessK.push_back(temp);
		else greaterK.push_back(temp);

		if (hash[address][1] == -1)break;
		else address = hash[address][1];
	}
	//开始输出
	for (int i = 0; i < negative.size(); i++){
		if (i != negative.size() - 1)printf("%05d %d %05d\n", negative[i].address, negative[i].data, negative[i + 1].address);
		else if (lessK.size() == 0){
			if (greaterK.size() != 0)printf("%05d %d %05d\n", negative[i].address, negative[i].data, greaterK[0].address);
			else printf("%05d %d -1\n", negative[i].address, negative[i].data);
		}
		else printf("%05d %d %05d\n", negative[i].address, negative[i].data, lessK[0].address);
	}
	for (int i = 0; i < lessK.size(); i++){
		if (i != lessK.size() - 1)printf("%05d %d %05d\n", lessK[i].address, lessK[i].data, lessK[i + 1].address);
		else if (greaterK.size() == 0) printf("%05d %d -1\n",lessK[i].address, lessK[i].data);
		else printf("%05d %d %05d\n", lessK[i].address, lessK[i].data, greaterK[0].address);
	}
	for (int i = 0; i < greaterK.size(); i++){
		if (i != greaterK.size() - 1)printf("%05d %d %05d\n", greaterK[i].address, greaterK[i].data, greaterK[i + 1].address);
		else printf("%05d %d -1\n", greaterK[i].address, greaterK[i].data);
	}
	system("pause");
	return 0;
}
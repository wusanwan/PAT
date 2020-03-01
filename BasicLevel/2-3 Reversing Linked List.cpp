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
	vector<node>list;
	while (1){	//根据实际的顺序，打包扔进vector里，避免排序造成的时间浪费
		node temp;
		temp.address = address;
		temp.data = hash[address][0];
		temp.next = hash[address][1];
		list.push_back(temp);
		if (hash[address][1] == -1)break;
		else address = hash[address][1];
	}
	//开始翻转。需要注意全部都能翻转完的情况
	int num = list.size() / K;
	int rest = list.size() % K;
	for (int i = 0; i < num; i++){
		for (int j = K-1; j >= 0; j--){
			if (!j&& i == num - 1 && !rest){
				list[i * K + j].next = -1;
			    printf("%05d %d %d\n", list[i*K + j].address, list[i*K + j].data, list[i * K + j].next);
			}
			else{
				if (j == 0 && i != num - 1) list[i * K + j].next = list[(i + 2)*K - 1].address;
				else if (j == 0) list[i * K + j].next = list[(i + 1) * K].address;
				else list[i * K + j].next = list[i * K + j - 1].address;
			    printf("%05d %d %05d\n", list[i*K + j].address, list[i*K + j].data, list[i * K + j].next);
			}
			
		}
	}
	for (int i = K*num; i < list.size(); i++){
		if (i != list.size() - 1)  printf("%05d %d %05d\n", list[i].address, list[i].data, list[i].next);
		else  printf("%05d %d %d\n", list[i].address, list[i].data, list[i].next);
	}
	system("pause");
	return 0;
}
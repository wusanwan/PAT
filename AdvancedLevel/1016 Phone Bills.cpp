//1016 Phone Bills
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct record{
	string name,time,statu;
	int month;
};
bool cmp(record a, record b){
	if (a.name == b.name)return a.time < b.time;
	else return a.name < b.name;
}
double bill(double cost[], int sumcost,string start, string end, int&time){//money and time
	int d1, d2, h1, h2, m1, m2;
	sscanf(start.c_str(), "%d:%d:%d", &d1, &h1, &m1);
	sscanf(end.c_str(), "%d:%d:%d", &d2, &h2, &m2);
	double sum=0;
	time = 0;
	if (d1 != d2){
		for (int i = h1 + 1; i < 24; i++){
			time += 60;
			sum += cost[i]*60;
		}
		for (int i = 0; i < h2; i++){
			time += 60;
			sum += cost[i]*60;
		}
		time += (d2 - d1 - 1) * 24 * 60 + 60 - m1 + m2;
		sum += (d2 - d1 - 1)*sumcost * 60 + cost[h1] * (60 - m1) + cost[h2] * m2;
		return sum/100;
	}
	else if (h1 != h2){
		for (int i = h1 + 1; i < h2; i++){
			time += 60;
			sum += cost[i]*60;
		}
		time += 60 - m1 + m2;
		sum += cost[h1] * (60 - m1) + cost[h2] * m2;
		return sum/100;
	}
	else{
		time = m2 - m1;
		return cost[h1] * time/100;
	}
}
int main(){
	double cost[24];
	double sum = 0, pay, sumcost = 0;
	int N, start = 1;
	record list[1000];
	for (int i = 0; i < 24; i++){
		scanf("%lf", &cost[i]);
		sumcost += cost[i];
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		cin >> list[i].name >> list[i].month;
		cin.ignore(1) >> list[i].time >> list[i].statu;//用cin.ignore(1）忽略了一个：
	}
	sort(list, list + N, cmp);
	for (int i = 0; i < N-1; i++){
		if (start){
			sum = 0;
			printf("%s %02d\n", list[i].name.c_str(), list[i].month);
			start = 0;
		}
		if (list[i].name == list[i + 1].name && list[i].statu == "on-line"&&list[i + 1].statu == "off-line"){//找到第一条配对记录才算开始
			int time;
			pay = bill(cost,sumcost, list[i].time, list[i+1].time,time);
			sum += pay;
			printf("%s %s %d $%.2lf\n", list[i].time.c_str(), list[i+1].time.c_str(), time, pay);
		}	
		if (i==N-2||list[i].name != list[i + 1].name){//end
			start = 1;
			printf("Total amount: $%.2lf\n", sum);
		}
	}
	system("pause");
	return 0;
}
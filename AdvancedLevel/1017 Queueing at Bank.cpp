//1017 Queueing at Bank （25 分）
#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
using namespace std;
struct custom{
	float arrivetime;
	float processtime;
};
bool cmp(custom a, custom b){//别写错了 不是if（）return a<b那得运算符重载了，这里就等于定义排序规则就是按照arrivetime排的
	return a.arrivetime < b.arrivetime;
}
int main(){
	//input
	int N,customs, windows,hh,mm,ss,temp;
	custom list[10000];
	float window[100];//存储结束时间
	scanf("%d %d", &N, &windows);
	fill(window, window + windows, 480);
	customs =0;
	for (int i = 0; i < N; i++){
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &temp);
		float time = hh * 3600 + mm * 60 + ss;//否则对秒不敏感
		if (time <= 61200){//别一个读了另一个没读
			list[customs].arrivetime = time / 60;
			list[customs].processtime = temp;
			customs++;
		}
	}
	sort(list, list + customs, cmp);
	//open door
	float  sumtime = 0;
	int nextindex = -1;
	for (int order = 0; order < customs; order++){
		//找最快窗口
		float nexttime = 9999;//每次都得设置
		for (int i = 0; i < windows; i++){
			if (window[i] < nexttime){
				nextindex = i;
				nexttime = window[i];
			}
		}
		if (list[order].arrivetime>=nexttime){//空闲直接可用,无等待时间
			window[nextindex] = list[order].arrivetime + list[order].processtime;
		}
		else{//忙碌等待中，包括提早到的情况
			window[nextindex] = nexttime + list[order].processtime;
			sumtime += nexttime - list[order].arrivetime;//包括早到了
		}
	}
	printf("%.1f", sumtime / customs);
	system("pause");
	return 0;
}
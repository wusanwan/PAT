//1017 Queueing at Bank ��25 �֣�
#pragma warning(disable:4996)
#include<cstdio>
#include<algorithm>
using namespace std;
struct custom{
	float arrivetime;
	float processtime;
};
bool cmp(custom a, custom b){//��д���� ����if����return a<b�ǵ�����������ˣ�����͵��ڶ������������ǰ���arrivetime�ŵ�
	return a.arrivetime < b.arrivetime;
}
int main(){
	//input
	int N,customs, windows,hh,mm,ss,temp;
	custom list[10000];
	float window[100];//�洢����ʱ��
	scanf("%d %d", &N, &windows);
	fill(window, window + windows, 480);
	customs =0;
	for (int i = 0; i < N; i++){
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &temp);
		float time = hh * 3600 + mm * 60 + ss;//������벻����
		if (time <= 61200){//��һ��������һ��û��
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
		//����촰��
		float nexttime = 9999;//ÿ�ζ�������
		for (int i = 0; i < windows; i++){
			if (window[i] < nexttime){
				nextindex = i;
				nexttime = window[i];
			}
		}
		if (list[order].arrivetime>=nexttime){//����ֱ�ӿ���,�޵ȴ�ʱ��
			window[nextindex] = list[order].arrivetime + list[order].processtime;
		}
		else{//æµ�ȴ��У��������絽�����
			window[nextindex] = nexttime + list[order].processtime;
			sumtime += nexttime - list[order].arrivetime;//�����絽��
		}
	}
	printf("%.1f", sumtime / customs);
	system("pause");
	return 0;
}
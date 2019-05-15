//1006 Sign In and Sign Out 
#pragma warning(disable:4996)
#include<cstdio>
#include<stdlib.h>
struct time{
	int hour;
	int minute;
	int second;
};
struct item{
	char IDnumber[15];
	time in;
	time out;
};
bool cmptime(time a,time b){//a is earlier than b.
	if (a.hour < b.hour)return true;
	else if (a.hour>b.hour)return false;
	else if (a.minute < b.minute)return true;
	else if (a.minute>b.minute)return false;
	else if (a.second < b.second)return true;
	else return false;
}
int main(){
	//input
	int num;//number of items
	scanf("%d", &num);
	item item1[1000];
	int early=0, late=0;//index of the earliest,latest
	for (int i = 0; i < num; i++){
		scanf("%s %d:%d:%d %d:%d:%d", &item1[i].IDnumber, &item1[i].in.hour, &item1[i].in.minute, &item1[i].in.second, &item1[i].out.hour, &item1[i].out.minute, &item1[i].out.second);
		//in-early
		if (cmptime(item1[i].in, item1[early].in))early = i;
		//out-late
		if (cmptime(item1[late].out, item1[i].out))late = i;
	}
	printf("%s %s", item1[early].IDnumber, item1[late].IDnumber);
	system("pause");
	return 0;
}
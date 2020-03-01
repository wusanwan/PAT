//1042 Shuffling Machine
#include<cstdio>
#include <stdlib.h>
using namespace std;
void shuffle(int order[], int result[], int RepeatTime){
	//order是给定循环顺序，result是对应序号所在位置。
	//初始化
	for (int i = 0; i < 54; i++)
		result[i] = i;
	//shuffle
	for (int i = 1; i <= RepeatTime; i++){
		for (int j = 0; j < 54; j++){
			result[j] = order[result[j]]-1;//注意给的order是和数组序号不对应的
		}
	}
}
int main(){
	//input
	int RepeatTime;
	scanf("%d", &RepeatTime);
	int order[54];
	for (int i = 0; i < 54; i++){
		scanf("%d", &order[i]);
	}
	//shuffling
	int result[54];
	shuffle(order, result, RepeatTime);
	//output 其实也可以考虑写结构体,二维数组什么的，因为54不算大这里就直接搞了
	for (int i = 0; i < 54; i++){
		int pos;
		for (int j = 0; j < 54; j++){//寻找位置
			if (result[j] == i) {
				pos = j;
				break;
			}
		}
		//这边也可以再进行优化 用char a[5]=SHCDJ什么的，i+1/13
		if (0 <= pos && pos < 13)            //别写成0 <= pos < 13了！！
			printf("S%d", pos + 1);
		else if (13 <= pos && pos < 26)
			printf("H%d", pos - 12);
		else if (26 <= pos&& pos  < 39)
			printf("C%d", pos - 25);
		else if (39 <= pos && pos < 52)
			printf("D%d", pos - 38);
		else
			printf("J%d", pos - 51);
		if (i != 53)printf(" ");//追加空格
	}
	system("pause");  //找不到标识符 include#include <stdlib.h>
	return 0;
}
//1042 Shuffling Machine
#include<cstdio>
#include <stdlib.h>
using namespace std;
void shuffle(int order[], int result[], int RepeatTime){
	//order�Ǹ���ѭ��˳��result�Ƕ�Ӧ�������λ�á�
	//��ʼ��
	for (int i = 0; i < 54; i++)
		result[i] = i;
	//shuffle
	for (int i = 1; i <= RepeatTime; i++){
		for (int j = 0; j < 54; j++){
			result[j] = order[result[j]]-1;//ע�����order�Ǻ�������Ų���Ӧ��
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
	//output ��ʵҲ���Կ���д�ṹ��,��ά����ʲô�ģ���Ϊ54����������ֱ�Ӹ���
	for (int i = 0; i < 54; i++){
		int pos;
		for (int j = 0; j < 54; j++){//Ѱ��λ��
			if (result[j] == i) {
				pos = j;
				break;
			}
		}
		//���Ҳ�����ٽ����Ż� ��char a[5]=SHCDJʲô�ģ�i+1/13
		if (0 <= pos && pos < 13)            //��д��0 <= pos < 13�ˣ���
			printf("S%d", pos + 1);
		else if (13 <= pos && pos < 26)
			printf("H%d", pos - 12);
		else if (26 <= pos&& pos  < 39)
			printf("C%d", pos - 25);
		else if (39 <= pos && pos < 52)
			printf("D%d", pos - 38);
		else
			printf("J%d", pos - 51);
		if (i != 53)printf(" ");//׷�ӿո�
	}
	system("pause");  //�Ҳ�����ʶ�� include#include <stdlib.h>
	return 0;
}
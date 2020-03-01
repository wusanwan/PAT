//1082 Read Number in Chinese
#pragma warning (disable:4996)
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	long long n;
	char str[10];//
	char name[5][5] = { "Wan", "Shi", "Bai", "Qian", "Yi" };
	char number[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	string digit;
	scanf("%lld", &n);
	if (n< 0){//处理负号
		printf("Fu ");
		n = -n;
	}
	sprintf(str, "%lld", n);
	digit = str;
	reverse(digit.begin(),digit.end());//注意reverse的用法
	int pos;//找到最后一位的位置,不输出空格。
	for (pos = 0; pos <= digit.length() - 1; pos++){
		if (digit[pos] != '0')break;
	}
	for (int i = digit.length() - 1; i >= 0;i--){
		if (i== 8){//亿位
			printf("%s %s", number[digit[i] - '0'], name[4]);
		}
		else if (i == 4){//万位
			if (digit[i] == '0')printf("%s", name[0]);
			else printf("%s %s", number[digit[i] - '0'], name[0]);
		}
		else if (i == 0){//个位
			if (digit[i] != '0')printf("%s", number[digit[i] - '0']);
			if (digit[i] == '0' && digit.length() == 1)printf("ling");//对单个0情况的补充
		}
		else{//其他位
			if (digit[i] == '0'){//有零
				if (digit[i - 1] == '0')//1.多个零只打印一个零 2.个位，万位的零不打印
					continue;
				else printf("%s", number[0]);
			}
			else{//1,shi2,bai,3,qian,4wan,5,shi 6,
				printf("%s %s", number[digit[i] - '0'], name[i % 4]);
			}
		}
		if (i > pos)printf(" ");
	}
	system("pause");
	return 0;
}
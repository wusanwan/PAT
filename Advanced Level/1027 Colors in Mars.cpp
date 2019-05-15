//1027 Colors in Mars
#pragma warning(disable:4996)
#include<cstdio>
#include<string.h>
#include<cstdlib>
int main(){
	int color[3];
	scanf("%d %d %d", &color[0], &color[1], &color[2]);
	char radix[14] = "0123456789ABC";
	printf("#");
	for (int i = 0; i < 3; i++){
		char num[2];
		int k = 0;
		do{
			num[k++] = radix[color[i] % 13];
			color[i] = color[i] / 13;
		} while (color[i] != 0);
		if (k == 1)printf("0%c", num[0]);
		else printf("%c%c", num[1], num[0]);
	}
	system("pause");
	return 0;
}

//1069 The Black Hole of Numbers
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int origin;
	scanf_s("%d", &origin);
	int flag = 0;
	int pos[4];
	do {
		for (int i = 0; i < 4; i++){
			pos[i] = origin / pow(10, 3 - i);
			origin -= pos[i] * pow(10, 3 - i);
		}
		int bigger = 0, smaller = 0;
		sort(pos, pos + 4);
		for (int i = 0; i < 4; i++){
			smaller += pos[i] * pow(10, 3 - i);
			bigger += pos[i] * pow(10, i);
		}
		int diff = bigger - smaller;
		printf("%04d - %04d = %04d\n", bigger, smaller, diff);  //ÓÃ%0md²¹×ãÁã
		if (diff == 0 || diff == 6174)flag = 1;
		else origin = diff;
	} while (!flag);
	system("pause");
	return 0;
}
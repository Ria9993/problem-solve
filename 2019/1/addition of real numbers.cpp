#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define max(x,y) x>y?(x):(y)
#define SP i-(100-strlen(num))
using namespace std;
char num[110];
char num2[110];
char sum[210];
void chk(int n) {
	if (sum[n] == '9'+1) {
		if (sum[n - 1]==0) sum[n - 1] = '1';
		else sum[n - 1]++;
		sum[n] = '0';
		chk(--n);
	}
}
int main() {
	int nlen=0, mlen=0;
	while (true) {
		char mi,flag=0;
		num[0] = NULL;
		scanf(" %[^-.]", num);
		if (num[0] == NULL) {
			scanf("%*1c"); flag = true;
		}
		if (num[0] == '0') return 0;
		scanf("%*1c %s", num2);
		nlen = max(nlen, strlen(num));
		mlen = max(mlen, strlen(num2));

		for (int i = 100 - strlen(num); i<100 + strlen(num2); i++) {
			sum[i] = ((sum[i] - (sum[i] != 0 ? '0' : 0) + (i < 100 ? num[SP] : num2[SP - strlen(num)]) - '0')) + '0';
			if ((sum[i] - (sum[i] != 0 ? '0' : 0)) >= 10) {
				sum[i] -= 10;
				if (sum[i - 1] == 0) sum[i - 1] = '1';
				else sum[i - 1]++;
				chk(i - 1);
				if (sum[100 - nlen-1] != 0)nlen++;
				//if (sum[100 + mlen] == 0)mlen--;
			}
		}
		while(sum[100 + mlen -1] == '0'&&mlen!=1)mlen--;
		for (int i = 100 - nlen; i < 100 + mlen; i++) {
			if (i == 100)printf(".");
			printf("%1c", sum[i]);
		}
		printf("\n");
	}
	return 0;
}
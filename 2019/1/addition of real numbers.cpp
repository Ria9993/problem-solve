#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define max(x,y) x>y?(x):(y)
#define SP i-(100-strlen(num))
#define EP i+(100-strlen(num2))

using namespace std;
char num[110], num2[110];
char sum[210];
void chk(int n,char type) {
	switch(type) {
		case '+' : if (sum[n] == '9'+1) {
			if (sum[n - 1]==0) sum[n - 1] = '1';
			else sum[n - 1]++;
			sum[n] = '0';
			chk(n-1,'-');
		} break;
		case '-' : if(sum[n]== '0'-1){
			if(sum[n])
			chk(n+1,'+');
		} break;
	}
}
int main() {
	bool sumFlag=false,flag=false; //sum의 부호, 연산종류 [true일시 '-']
	int nlen=0, mlen=0;
	while (true) {
		flag=false;
		num[0] = NULL; 	
		scanf(" %[^-.]", num);
		if (num[0] == NULL) {
			scanf("%*1c"); flag = true; // 마이너스 연산
		}
		if (num[0] == '0') return 0;
		scanf("%*1c %s", num2);
		nlen = max(nlen, strlen(num));	
		mlen = max(mlen, strlen(num2));

		if(!flag) { //+
			for (int i = 100 - strlen(num); i<100 + strlen(num2); i++) {
				sum[i] = ((sum[i] - (sum[i] != 0 ? '0' : 0) + (i < 100 ? num[SP] : num2[SP - strlen(num)]) - '0')) + '0';
				if ((sum[i] - (sum[i] != 0 ? '0' : 0)) >= 10) {
					sum[i] -= 10;
					if (sum[i - 1] == 0) sum[i - 1] = '1';
					else sum[i - 1]++;
					chk(i - 1,'+');
					if (sum[100 - nlen-1] != 0)nlen++;
					//if (sum[100 + mlen] == 0)mlen--;
				}
			}
		}
		else { //-
			for(int i = 100 + strlen(num2)-1;i>=100-strlen(num);i--) {
				sum[i] = ((sum[i] - (sum[i] != 0 ? '0' : 0) - (i < 100 ? num[SP] : num2[SP - strlen(num)]) - '0')) + '0';
				if ((sum[i] - (sum[i] != 0 ? '0' : 0)) < 0) {
					sum[i] += 10;
					if (sum[i - 1] == 0) sumFlag=true;
					else sum[i - 1]++;
					chk(i - 1,'-');
					if (sum[100 - nlen-1] != 0)nlen++;
					//if (sum[100 + mlen] == 0)mlen--;
				}
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
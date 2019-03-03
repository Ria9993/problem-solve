#pragma warning (disable:4996)                               
#include<stdio.h>
#include<string.h>

int six(char x, int y) {
	if (x >= 'A' && x <= 'Z') {
		return (x - 55) * y;
	}
	else if (x >= '1'&&x <= '9') return (x - '0') * y;
	else return 0;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdin);
	char a[1000], b[1000];
	int c, st, tr, d = 1, xx[10000] = { 0 },cnt=0;
	__int64 x=0, y=0,xy=0;
    
	gets_s(a);
	gets_s(b);
	st = strlen(a);
	tr = strlen(b);
	strrev(a);
	strrev(b);
	scanf("%d", &c);
	for (int i = 0; i < st; i++) {
		x += six(a[i],d);
		d *= 16;
	}
	d = 1;	
	for (int i = 0; i < tr; i++) {
		y += six(b[i], d);
		d *= 16;
	}
	xy = x * y;
	while (1) {
		if (xy <= 0) break;
		xx[cnt++] = xy % c;
		xy /= c;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		if (xx[i] >= 10) {
			printf("%c", xx[i] + 55);
		}
		else {
			printf("%d", xx[i]);
		}
	}
}
#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
typedef struct _b { int za; int mo; }_b;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return (x * (y / gcd(y, x))); }
int mx(_b x) { //최대 이집티안분수
	double tmp = (double)x.za / x.mo;
	for (int i = 2;; i++) {
		if (fabs(tmp - (double)1 / i) < 0.00001f) return i; //x분수와 1/i가 같을경우
		if (tmp > (double)1 / i) return i;
	}
}	
void f(_b x) {
	int tmp = mx(x); //최대 이집티안분수의 분모
	printf("1/%d", tmp);
	int tm = lcm(tmp, x.mo); //통분시 분모
	int tz = ((tm / x.mo)*x.za) - (tm / tmp); //통분시 분자
	if (tz == 1) { printf("+1/%d",tm); return;}//종료조건
	printf("+");
	f({ tz,tm });//통분
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	_b x;
	scanf("%d", &x.za);
	scanf("%d", &x.mo);
	f({ x.za,x.mo });
	return 0;
}
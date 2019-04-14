#pragma warning(disable:4996)
#include <stdio.h>
int N, M, tmp, day[101] = { false, };
struct _cost{unsigned long long int eva;unsigned long long int real;}mem[101];
void f(int n, unsigned long long int cost, int coupon) {
	if (n > N+1 || (mem[n].eva < cost - coupon && mem[n].eva))return;
	if (day[n]) { f(n + 1, cost, coupon); return;}
	mem[n] = { cost - coupon, cost };
	f(n + 5, cost + 37000, coupon + 2);
	f(n + 3, cost + 25000, coupon + 1);
	if (coupon >= 3) f(n + 1, cost, coupon - 3);
	else f(n + 1, cost + 10000, coupon);
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i<M; i++) { scanf("%d", &tmp); day[tmp] = true; }
	f(1, 0, 0);
	printf("%lld", mem[N+1].real);
	return 0;
}
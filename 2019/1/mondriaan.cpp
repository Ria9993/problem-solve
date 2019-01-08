#include <stdio.h>

int DATA[100] = { 1,2,NULL };
int f(int n) {
	if (!DATA[n]) {
		int tmp = f(n - 1) * 2 + f(n - 2) * 3;
		for (int i = 3; i <= n; i++)tmp += f(n - i) * 2;
		return DATA[n] = tmp % 10;
	}
	return DATA[n];
}
int main() {
	int a;
	scanf("%d", &a);
	printf("%d", f(a));
	return 0;
}
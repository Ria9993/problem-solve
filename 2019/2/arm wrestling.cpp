#include <stdio.h>
int n;
int f(int len, int sum) {
	if (sum == n)return 1;
	if (len >= n * 2 - 1)return 0;
	return f(len + 1, sum) + f(len + 1, sum + 1);
}
int main() {
	scanf("%d", &n);
	printf("%d", f(0, 0));
	return 0;
}
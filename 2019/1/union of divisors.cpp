#include <stdio.h>
#define max(x,y) (x>y?(x):(y))
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= max(n,m); i++)
		if (!(n % i) || !(m % i))
			printf("%d ", i);
}
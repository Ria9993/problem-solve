#include <stdio.h>
#define INF -1
int main() {
	int n, sum = 0, maxP = INF, minP = INF;
	double rate = 0, max = INF, min = INF;
	char tmp;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &tmp);
		sum += tmp == 'W';
		rate = (double)sum / i;
		if ((max == INF || rate >= max) && i >= 3) {
			max = rate;
			maxP = i;
		}
		if ((min == INF || rate <= min) && i >= 3) {
			min = rate;
			minP = i;
		}
	}
	printf("%d %d", maxP, minP);
}
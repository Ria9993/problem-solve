#include <stdio.h>

int main() {
	int p1, p2, n, now;
	int tmp, next = 1;
	int l[1000], cnt = 0;
	int i, j;
	scanf("%d %d %d", &p1, &p2, &n);
	for (; p1 <= p2; p1++) {
		now = p1;
		for (i = 0; now / 10 != 0;i++,now=tmp)for (tmp=1; now != 0; now /= 10)tmp *= now % 10 ? now % 10 : 1;
		if (i == n)l[cnt++] = p1;
	}
	printf("%d\n", cnt);
	for (i = 0; i<cnt; i++)printf("%d\n", l[i]);
	return 0;
}
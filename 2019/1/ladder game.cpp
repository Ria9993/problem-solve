#include <stdio.h>

int main() {
	int n, m;
	int p[30] = { 0, };
	for (int i = 0; i<30; i++)p[i] = i;

	scanf("%d %d", &n, &m);

	for (int i = 0; i<m; i++) {
		int l;
		scanf("%d", &l);
		for (int j = 0; j<n; j++) {
			if (p[j] == l - 1)p[j] = l;
			else if (p[j] == l)p[j] = l - 1;
		}
	}
	for (int i = 0; i<n; i++) printf("%d %c\n", i + 1, p[i] + 'A');
	return 0;
}
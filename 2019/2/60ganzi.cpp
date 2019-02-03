#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	char day[][10] = { { "Sunday" } ,{ "Monday" } ,{ "Tuesday" } ,{ "Wednesday" } ,{ "Thursday" } ,{ "Friday" } ,{ "Saturday" } };
	int n;
	scanf("%d", &n);
	printf("%c%c ", (n+6) % 10 + 'A', (n+8) % 12 + 'a');
	printf("%s", day[(((n-1) * 365) + ((n-1) / 4) - ((n-1) / 100) + ((n-1) / 400) + 1) % 7]);
	return 0;
}
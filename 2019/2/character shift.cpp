#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
int main() {
	char s, e;
	int n, len;
	char arr[50] = { 0, };

	scanf(" %c %c %d", &s, &e, &n);
	len = e - s;

	for (int i = 0; i<len; i++)arr[i] = s + i;
	for (int i = 0; i<len; i++)printf("%c", arr[(i + n-1) % len]);
	return 0;
}
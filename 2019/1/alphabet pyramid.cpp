#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n,len=0;
	char ab, tstr[50] = { 0, };
	scanf("%c", &ab);
	scanf("%d", &n);
	if (!isupper(ab) || n > 24) {printf("입력에러!");exit(0);}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n-1; j++)printf(" ");
		for (int j = 1,len=0; j <= (i * 2) + 1; j++) {
			tstr[len++] = ab++;
			if (ab > 'Z')ab = 'A';
		}
		printf("%s", i % 2 ? tstr: strrev(tstr));
		memset(tstr, 0, sizeof(tstr));
		printf("\n");
	}
	return 0;
}
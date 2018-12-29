#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	char str[110] = { 0, };
	scanf("%[^\n]", str);
	int cnt = strlen(str);
	for (int i = 0; i<6; i++) {
		for (int j = 0; j < (cnt / 6) + (cnt % 6 ? 1 : 0); j++) {
			switch (str[(j * 6) + i]) {
				case ' ' : printf("*"); break;
				case '\0': printf("."); break;
				case '*' : printf(" "); break;
				case '.' : continue; break;
				default  : printf("%c", str[(j * 6) + i]); break;
			}
		}
	}
	return 0;
}
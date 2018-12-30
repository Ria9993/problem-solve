#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
	char str[1100] = { 0, };
	bool flag = false;
	scanf("%[^\n]", str);
	int cnt = strlen(str);
	for (int i = 0; i<cnt; i++) if (str[i] == '*') flag = true;
	if (flag) { //복호화
		for (int j = 0; j < (cnt / 6) + (cnt % 6 ? 1 : 0); j++) {
			for (int i = 0; i < 6; i++) {
				switch (str[(i * (cnt/6)) + j]) {
					case '*': printf(" "); break;
					case '.': continue; break;
					default: printf("%c", str[(i * (cnt / 6)) + j]); break;
				}
			}
		}
		return 0;
	}
	for (int i = 0; i<6; i++) { //암호화
		for (int j = 0; j < (cnt / 6) + (cnt % 6 ? 1 : 0); j++) {
			switch (str[(j * 6) + i]) {
			case ' ': printf("*"); break;
			case '\0': printf("."); break;
			default: printf("%c", str[(j * 6) + i]); break;
			}
		}
	}
	return 0;
}
#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
int xp[2][4] = { { 1,0,-1,0 },{ 0,1,0,-1 } };
int yp[2][4] = { { 0,1,0,-1 },{ 1,0,-1,0 } };

int main() {
	int map[100][100] = { 0, }, n, x = 0, y = 0, cnt;
	char mod, s;

	scanf("%d %c", &n, &mod);
	cnt = n * 10;
	mod = mod == 'R' ? 0 : 1;
	mod ? y -= 1 : x -= 1;

	scanf(" %c", &s);
	int now=isupper(s)?s:s-'0';

	for (int i = 0; cnt; i = i == 3 ? 0 : i + 1, cnt -= 5) {
		for (int j = 0; j<cnt / 10; j++) {
			x += xp[mod][i];
			y += yp[mod][i];
			map[y][x] = now++;
			if (isupper(s))(now == 'Z' + 1) ? now = 'A' : NULL;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf(isupper(s) ? "%3c " : "%2d ", map[i][j]);
		printf("\n");
	}
	return 0;
}
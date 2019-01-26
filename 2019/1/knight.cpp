#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define INF 99999999
#define dis2 abs(e.y-(y+wy[i]))+abs(e.x-(x+wx[i]))
typedef struct p{int y;int x;}p;
p s, e;
bool flag[110][110] = { 0, };
int n;
int wy[8] = { -2,-2,-1,-1,1,1,2,2 };
int wx[8] = { -1,1,-2,2,-2,2,-1,1 };
void f(int y, int x, int len, int llen) {
	if (flag[y][x])return;
	if (y >= n || y < 0 || x >= n || x < 0)return;
	if (y == e.y&&x == e.x) {printf("%d", len); exit(0);}
	flag[y][x] = true;
	bool fl[8] = { false, };
	for (int o = 0; o<8; o++) {
		int min = -1, mini;
		for (int i = 0; i<8; i++)if ((min>dis2 || min == -1) && !fl[i]) { min = dis2; mini = i; }
		if (min > llen)return;
		f(y + wy[mini], x + wx[mini], len + 1, min);
		fl[mini] = true;
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d %d", &s.y, &s.x);
	scanf("%d %d", &e.y, &e.x);
	f(s.y, s.x, 0, INF);
	return 0;
}
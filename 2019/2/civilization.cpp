#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <Windows.h>

typedef struct _xy {
	int x;
	int y;
	int color;
}_xy;
_xy queue[5000000] = { 0, };
_xy Cqueue[5000000] = { 0, };
int map[2010][2010] = { { 0, }, };
bool Cmap[2010][2010] = { { 0, }, };
int top = 0, tail = 0;
int Ctop = 0, Ctail = 0;
bool check[100010] = { 0, };
int mapSize, N;
int cnt = 0;

void push(int x, int y, int color) { if (x>0 && x<=mapSize&&y>0 && y<= mapSize)if(map[x][y]==0)queue[top++] = { x,y,color }; }
void push(int x, int y) { if (x>0 && x<= mapSize &&y>0 && y<= mapSize)queue[top++] = { x,y }; }
_xy pop() { return queue[tail++]; }
void Cpush(int x, int y) { if (x>0 && x <= mapSize && y>0 && y <= mapSize)if(Cmap[x][y]==0)Cqueue[Ctop++] = { x,y }; }
_xy Cpop() { return Cqueue[Ctail++]; }

int main() {
	int x, y, len;
	scanf("%d %d", &mapSize, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &x, &y);
		push(x, y,i);
	}
	for (len = 0; tail<top; len++) {
		int ltop = top;
		for (int j = 0; tail<ltop; j++) {
			//_xy tmp = pop();
			//bfs(tmp);
			_xy loc = pop();
			if (!(loc.x > 0 && loc.x <= mapSize && loc.y > 0 && loc.y <= mapSize))continue;
			if (map[loc.x][loc.y])continue;
			map[loc.x][loc.y] = loc.color;
			push(loc.x + 1, loc.y, map[loc.x][loc.y]);
			push(loc.x - 1, loc.y, map[loc.x][loc.y]);
			push(loc.x, loc.y + 1, map[loc.x][loc.y]);
			push(loc.x, loc.y - 1, map[loc.x][loc.y]);
		}
		//chk(x, y);
		Cpush(x, y);
		for(;Ctail<Ctop;) {
			system("cls");
			for (int j = 1; j <= mapSize; j++) {
				for (int k = 1; k <= mapSize; k++) {
					printf("%d", Cmap[j][k]);
				}
				printf("\n");
			}
			_xy now = Cpop();
			if (!(now.x > 0 && now.x <= mapSize && now.y > 0 && now.y <= mapSize))continue;
			if (map[now.x][now.y] == 0)continue;
			if (Cmap[now.x][now.y])continue;
			else Cmap[now.x][now.y] = true;
			if (!check[map[now.x][now.y]]) { check[map[now.x][now.y]] = true; cnt++; }
			if (cnt == N)break;
			Cpush(now.x + 1, now.y);
			Cpush(now.x - 1, now.y);
			Cpush(now.x, now.y + 1);
			Cpush(now.x, now.y - 1);
		}
		Ctail = Ctop = 0;
		if (cnt == N) {
			printf("%d", len);
			return 0;
		}
		else {
			cnt = 0;
			memset(check, false, sizeof(check));
			memset(Cmap, false, sizeof(Cmap));
		}
	}
	return 0;
}
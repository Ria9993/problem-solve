#pragma warning(disable:4996)
#include <stdio.h>

typedef struct _xy {
	int y;
	int x;
	int from;
}_xy;
_xy civ[100010];
_xy stack[4000010];
_xy subStack[4000010];
int top = 0, subTop = 0;

_xy touch[4000010];
int touchCnt = 0;

bool chk[100010] = { false, };
int cntNum = 0;

int map[2010][2010] = { 0, };
int mapSize, num;

void bfs(int y, int x, int from);
void nextChk(int y, int x, int from);
void push(int y, int x, int from);
_xy pop();
void subCpy();

int main() {
	scanf("%d %d", &mapSize, &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d %d", &civ[i].y, &civ[i].x);
		push(civ[i].y, civ[i].x, i);
	}
	for (int res = 0;; res++) {
		subCpy();
		int temp = top;
		while (top) {
			_xy now = pop();
			bfs(now.y, now.x, now.from);
		}
		//for (int i = 0; i < temp; i++) {
		//	nextChk(stack[i].y, stack[i].x, stack[i].from);
		//}
		int chkCnt = 0;
		int tmp = touchCnt;
		while (touchCnt) { //다 만났는지 검사
			if (!chk[touch[touchCnt].x]&& touch[touchCnt].x) {
				chk[touch[touchCnt].x] = true;
				chkCnt++;
			}
			if (!chk[touch[touchCnt].y]&& touch[touchCnt].y) {
				chk[touch[touchCnt].y] = true;
				chkCnt++;
			}
			if (chkCnt == num) { //모든문명이 만남
				printf("%d", res);
				return 0;
			}
			touchCnt--;
		}

		while(tmp) {//chk reset
			chk[touch[touchCnt].x] = false;
			chk[touch[touchCnt].y] = false;
			tmp--;
		}
	}
	return 0;
}

void push(int y, int x, int from) {
	if (y <= 0 || y > mapSize || x <= 0 || x > mapSize) return;
	subStack[subTop++] = { y,x,from };
}
_xy pop() { return stack[--top]; }
void subCpy() { //sub to main
	top = subTop;
	for (int i = 0; i<subTop; i++)
		stack[i] = subStack[i];
	subTop = 0;
}

void bfs(int y, int x, int from) { //문명 전파
	map[y][x] = from;
	nextChk(y,x,from);
	push(y + 1, x, from);
	push(y - 1, x, from);
	push(y, x + 1, from);
	push(y, x - 1, from);
	return;
}
void nextChk(int y, int x, int from) { //닿앗는가
	if (from != map[y+1][x]&& map[y + 1][x]) { //다른문명임
		touch[touchCnt].y = from;
		touch[touchCnt++].x = map[y+1][x];
	}
	if (from != map[y-1][x]&& map[y - 1][x]) { //다른문명임
		touch[touchCnt].y = from;
		touch[touchCnt++].x = map[y-1][x];
	}
	if (from != map[y][x+1]&& map[y][x + 1]) { //다른문명임
		touch[touchCnt].y = from;
		touch[touchCnt++].x = map[y][x+1];
	}
	if (from != map[y][x-1]&& map[y][x - 1]) { //다른문명임
		touch[touchCnt].y = from;
		touch[touchCnt++].x = map[y][x-1];
	}
}
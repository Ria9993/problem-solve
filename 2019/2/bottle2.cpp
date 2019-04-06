#pragma warning(disable:4996)
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define INF -1
int A, B, C, D, mem[100010][4];
queue<pair<int, int>> q;
void push(int a, int b, int d) {
	if (a == 0) {
		if (mem[b][0] == INF) {
			mem[b][0] = d;
			q.push({ a,b });
		}
	}
	else if (a == A) {
		if (mem[b][1] == INF) {
			mem[b][1] = d;
			q.push({ a,b });
		}
	}
	else if (b == 0) {
		if (mem[a][2] == INF) {
			mem[a][2] = d;
			q.push({ a,b });
		}
	}
	else if (b == B) {
		if (mem[a][3] == INF) {
			mem[a][3] = d;
			q.push({ a,b });
		}
	}
	return;
}
int dis(int a, int b) {
	if (a == 0)return mem[b][0];
	if (a == A)return mem[b][1];
	if (b == 0)return mem[a][2];
	if (b == B)return mem[a][3];
	else return INF;
}
int main() {
	scanf("%d%d%d%d", &A, &B, &C, &D);
	for (int i = 0; i <= B; i++) {
		for (int j = 0; j<4; j++) {
			mem[i][j] = INF;
		}
	}
	push(0, 0, 0);
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		int d = dis(a, b);
		push(a, 0, d + 1);
		push(a, B, d + 1);
		push(0, b, d + 1);
		push(A, b, d + 1);
		int tmp = min(a, B - b);
		if(tmp!=INF)push(a - tmp, b + tmp, d + 1);
		tmp = min(A - a, b);
		if (tmp != INF)push(a + tmp, b - tmp, d + 1);
		//int tmp =
	}
	if (dis(C, D) == INF) printf("-1");
	else printf("%d", dis(C, D));
	return 0;
}

/*
mem[x][0] 0,x
mem[x][1] A,x
mem[x][2] x,0
mem[x][3] x,B
*/
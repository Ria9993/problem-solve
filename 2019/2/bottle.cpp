#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct bottle {
	int size;
	int amount;
}bottle;
bottle A, B;
int **D;
int agAmount, bgAmount; //최종목표

int M(int x, int y, int ySize, const char *res) {
 	if (x>ySize - y) {
		x -= ySize - y;
		y = ySize;
	}
	else {
		y += x;
		x = 0;
	}
	if (!strcmp(res, "src"))return x;
	if (!strcmp(res, "dest"))return y;
	else return -1;
}
int f(int a, int b, int cnt) {
	if (D[a][b] && D[a][b] <= cnt)return -1;
	else D[a][b] = cnt;
	if (a == agAmount && b == bgAmount)return 1;//goal
	//F
	f(A.size, b, cnt + 1);
	f(a, B.size, cnt + 1);
	//E
	f(0, b, cnt + 1);
	f(a, 0, cnt + 1);
	//M
	f(M(a, b, B.size, "src"), M(a, b, B.size, "dest"), cnt + 1);	
	f(M(b, a, A.size, "dest"), M(b, a, A.size, "src"), cnt + 1);	
	return 0;
}
int main() {
	scanf("%d %d", &A.size, &B.size);
	scanf("%d %d", &agAmount, &bgAmount);
	D = (int**)malloc(sizeof(int*)*(A.size + 10));
	for (int i = 0; i < A.size + 10; i++) {
		D[i] = (int*)malloc(sizeof(int)*(B.size + 10));
		memset(D[i], 0, sizeof(int)*(B.size+10));
	}
	f(0, 0, 0);
	printf("%d", D[agAmount][bgAmount]? D[agAmount][bgAmount]:-1);
	return 0;
}

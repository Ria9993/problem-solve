#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return (x * (y / gcd(y, x))); }
int main() {
	int n, m;
	int x=0, y=0;
	int cnt = 0, arr[10000];
	scanf("%d %d", &n, &m);
	int size = lcm(n, m);
	for (int i = 0;; i++) {
		if (i) {
			if (x == size && y == size) { for (int j = 0; j<cnt; j++)printf("%d ", arr[j]); printf("3"); return 0; }//3
			else if (x == size * 2 && y == size) { for (int j = 0; j<cnt; j++)printf("%d ", arr[j]); printf("4"); return 0; }//4
			else if (x == size && y == size * 2) { for (int j = 0; j<cnt; j++)printf("%d ", arr[j]); printf("2"); return 0; }//2
			else if (x == size * 2 && y == size * 2) { for (int j = 0; j<cnt; j++)printf("%d ", arr[j]); printf("1"); return 0; }//1
			if (x >= size * 2) { x = x % size; printf("W "); arr[cnt++] = 1; }//1 w
			if (x >= size) { arr[cnt++] = 2; printf("E ");
			} //2 e
			if (y >= size * 2) { x = x % size; printf("N "); arr[cnt++] = 3; }//3 n
			if (y >= size) { arr[cnt++] = 4; printf("S ");
			}//4 s

		}	
		y += n;	
		x += m;
	}
	return 0;
}
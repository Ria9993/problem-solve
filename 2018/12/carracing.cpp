#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int queue[1010] = { 0, }, top = 0, tail = 0;
void push(int n) { queue[top++] = n; }
int pop() { return queue[tail++]; }
int main() {
	int n, x, cnt = 1;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &x);
		if (cnt == x) cnt++;
		else if (cnt == queue[tail]) { push(x); pop(); cnt++; }
		else if (tail == top) push(x);
		else { printf("NO"); return 0; }
	}
	printf("YES");
	return 0;
}
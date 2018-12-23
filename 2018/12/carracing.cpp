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
	for (int i = 0; i<n||(top!=tail||i<n); i++) {
		if(i<n)scanf("%d", &x);
		if (cnt == x) cnt++;
		else if (cnt == queue[tail] && i >= n){
			pop(); cnt++;}
		else if (cnt == queue[tail]) { 
			push(x); pop(); cnt++; }
		else push(x);
	}
	if(tail==top) printf("YES");
	else printf("NO");
	return 0;
}
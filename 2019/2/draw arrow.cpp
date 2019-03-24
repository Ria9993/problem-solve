#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef struct _p {
	int color;
	int local;
}_p;
_p p[100010];
bool st(_p x, _p y) {
	if (x.color != y.color) return x.color<y.color;
	else return x.local<y.local;
}
long long int dis(int x, int y) { return abs(x - y); }
int main() {
	int n;
	long long int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d %d", &p[i].local, &p[i].color);
	sort(p, p + n, st);
	for (int i = 0, j = 0; i<n; i = j) {
		for (j = i; p[j].color == p[j - 1].color || j == i; j++) {
			if (j == i && p[j].color == p[j + 1].color)sum += dis(p[j].local, p[j + 1].local);
			else if (j != i && p[j].color != p[j + 1].color)sum += dis(p[j].local, p[j - 1].local);
			else if (j != i && p[j].color == p[j + 1].color) sum += min(dis(p[j].local, p[j + 1].local), dis(p[j].local, p[j - 1].local));
		}
	}
	printf("%lld", sum);
	return 0;
}
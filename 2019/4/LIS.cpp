#pragma warning(disable:4996)
#include <stdio.h>
int n,left,max,sum_a=0,sum_b=0,l,r;
int arr[100010] = { 0, }, tree[100010] = { 0, };
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){ 
		scanf("%d", &arr[i]);
		for (int j = i; j <= n; j += j & -j) tree[j] += arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] > sum_b - sum_a + arr[i])left = i;
		sum_a = sum_b = 0;
		for (int j = left-1; j; j -= j & -j) sum_a += tree[j];
		for (int j = i; j; j -= j & -j) sum_b += tree[j];
		if (sum_b - sum_a>max || i==1) {
			max = sum_b - sum_a;
			l = left;
			r = i;
		}
	}
	printf("%d %d %d", l, r, max);
	return 0;
}
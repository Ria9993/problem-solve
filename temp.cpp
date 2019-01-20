#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define max(x,y) x>y?(x):(y)
int n;
int arr[110] = { 0, };
bool flag[110] = { false, };
int line[110] = { 0, };

typedef struct pro {

}pro;
int f(int x, int y) {
	int sum=0,m=0;
	for (int i = x; i < n; i++) {
		for (int j = y; j + i <= n; j++) {
			if (arr[j] != arr[j + i] && flag[j]     == false
									 && flag[j + i] == false) {

				bool arrt[110];
				memcpy(arrt, arr, sizeof(arr));
				int linet[110];
				memcpy(linet, line, sizeof(line));

				m=max(m,f(x, y + 1));
				
				flag[j] = flag[j + i] = true;
				line[j] = j + i;
			}
		}
	}
	return sum;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%1d", &arr[i]);
	printf("%d\n", f(1, 1));
	for (int i = 1; i <= n; i++)
		if (line[i])
			printf("%d %d \n", i, line[i]);
}
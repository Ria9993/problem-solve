#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define as ans[j]
using namespace std;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, arr[30000][5], ans[5];
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<5; j++)scanf("%1d", &arr[i][j]);
	}
	for (int j = 0; j<5; j++)scanf("%1d", &ans[j]);
	for (int i = 0; i<n; i++) {
		int flag = 2;
		for (int j = 0; j<5; j++) {
			if (arr[i][j] == ans[j])continue;
			switch (arr[i][j]) {
				case 1: if (as == 2 || as == 4)continue;
				case 2: if (as == 1 || as == 5 || as == 3)continue;
				case 3: if (as == 2 || as == 6)continue;
				case 4: if (as == 1 || as == 5 || as == 7)continue;
				case 5: if (as == 2 || as == 4 || as == 6 || as == 8)continue;
				case 6: if (as == 3 || as == 5 || as == 9)continue;
				case 7: if (as == 4 || as == 8)continue;
				case 8: if (as == 5 || as == 7 || as == 9 || as == 0)continue;
				case 9: if (as == 6 || as == 8)continue;
				case 0: if (as == 8)continue;
			}
			flag--;
		}
		if (flag>0) {
			printf("OPEN"); return 0;
		}
	}
	printf("CLOSE");
	return 0;
}
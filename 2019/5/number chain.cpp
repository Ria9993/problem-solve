//not yet
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool backSort(int x, int b) { return x>b; }
int main() {
	char str[110], res[110], s1[110], s2[110];
	char list[110][110];
	int cnt = 1;
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)str[i] -= '0';
	int len = strlen(str);
	strcpy(s2, str);
	while (true) {
		strcpy(s1, s2);
		sort(s1, s1 + sizeof(char)*len);
		sort(s2, s2 + sizeof(char)*len, backSort);
		for (int i = len - 1; i >= 0; i--) {
			if (s2[i] - s1[i]<0)s2[i - 1]--;
			s2[i] = s2[i] - s1[i]<0 ? s2[i] - s1[i] + 10 : s2[i] - s1[i];
		}
		cnt++;
		int flag = 0;
		for (int i = 0; i < len; i++) if (s2[i] != str[i])flag = true;
		if (flag == false)break;
	}
	for (int i = 0; i < cnt; i++) for (int j = 0; j < strlen(list[i]); i++)list[i][j] += '0';
	for (int i = 0; i < strlen(str); i++)str[i] += '0';
	printf("%d\n", cnt);
	printf("%s", str);
	for (int i = 1; i<cnt; i++) printf("%s\n", list[i]);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//asc des
bool desSort(int x, int y) { return x>y; }
int Bint(char *str) {
	int sum = 0;
	for (int i = 0; i < strlen(str); i++)
		sum = (sum*10)+str[i] - '0';
	return sum;
}
char * Bstr(int n) {
	static char str[15];
	for (int i = 0; n != 0; n /= 10, i++) str[i] = n % 10 + '0';
	strrev(str);
	return str;
}
bool chk(int arr[], int n, int els ,int len) {
	for (int i = 0; i<len; i++)
		if (arr[i] == n && i != els)return true;
	return false;
}
bool chk(int arr[], int sint, int len) {
	int flag = 0;
	for (int i = 0; i<len; i++)flag += chk(arr, arr[i], i,len);
	return (bool)flag;
}
int main() {
	char str[15];
	int sint;
	int res[10000], cnt = 0, asc, des;	
	memset(res, 0, sizeof(res));

	scanf("%s", str);
	sint = Bint(str);
	res[cnt++] = sint;

	do {
		sort(str, str + strlen(str), desSort);
		des = Bint(str);
		sort(str, str + strlen(str));
		asc = Bint(str);

		res[cnt] = des - asc;
		strcpy(str, Bstr(res[cnt++]));
		} while (!chk(res, sint,cnt));
	printf("%d\n", cnt - 1);
	for (int i = 0; i<cnt - 1; i++)printf("%d\n", res[i]);
	return 0;
}
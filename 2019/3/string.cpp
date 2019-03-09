#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    char str[10000];
    scanf("%s",str);
    printf("%c%c",str[0],str[strlen(str)-1]);
	return 0;
}
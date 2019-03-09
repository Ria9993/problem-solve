#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char n;
    scanf("%c",&n);
    printf("%s",isupper(n)?"대문자":"소문자");
	return 0;
}
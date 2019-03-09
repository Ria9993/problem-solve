#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%s",a>b?"Yes":"No");
	return 0;
}
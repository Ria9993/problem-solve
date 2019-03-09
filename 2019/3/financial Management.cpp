#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	double sum=0;
    double tmp;
    for(int i=0;i<12;i++) {
        scanf("%lf",tmp);
        sum+=tmp;
    }
    printf("%.2lf",sum);
	return 0;
}
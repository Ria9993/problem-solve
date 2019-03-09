#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	double x,y,res;
    char ca;
    scanf("%lf%1c%lf",&x,&ca,&y);
    switch(ca) {
        case '+' : printf("%.2lf",x+y);
        case '-' : printf("%.2lf",x-y);
        case '*' : printf("%.2lf",x*y);
        case '/' : printf("%.2lf",x/y);
    }
	return 0;
}
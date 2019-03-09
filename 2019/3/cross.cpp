#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(((i==1||i==n)||i==n/2+1)
             ||((j==1||j==n)||j==n/2+1))printf("*");
             else printf(" ");
        }
        printf("\n");
    }
	return 0;
}
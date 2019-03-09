#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n,m;
    int tmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",tmp);if(m<tmp)m=tmp;
	printf("%d",m);
    return 0;
}
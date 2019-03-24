#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<n;i++){scanf("%d",&tmp);printf("%d ",tmp);}
	return 0;
}   
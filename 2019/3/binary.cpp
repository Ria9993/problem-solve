#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
    char binary[10000]={0,};
    scanf("%d",&n);
    sprintf(binary,"%b",n);
    strrev(binary);
    for(int i=0;i<strlen(binary);i++) {
        if(binary[i])printf("%d ",i+1);
    }
	return 0;
}
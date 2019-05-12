#pragma warning(disable:4996)
#include <stdio.h>
int N,M,cnt=0;
int main() {
    scanf("%d",&N);
    for(int i=N;i>1;i/=3,cnt++);
    printf("%d",cnt);
    return 0;
}
#pragma warning(disable:4996)
#include <stdio.h>

int arr[1010],max=0;
void ins(int p,int n) {
    if(arr[p]) for(int i=max;i>=p;i--)arr[i+1]=arr[i];
    arr[p]=n;
    max++;
    return;
}
int main() {
    int n,tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&tmp);ins(tmp,i);}
    for(int i=max-1;i>=0;i--)printf("%d ",arr[i]);
    return 0;
}
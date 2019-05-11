#pragma warning(disable:4996)
#include <stdio.h>
int arr[100010]={0,},len;
int res[100010]={0,},max=0;
int main() {
    int n;
    scanf("%d",&n);
    arr[0] = n;
    for(int i=n/2,j;i<=n;i++) {
        arr[1] = i;
        for(j=2;arr[j-2]-arr[j-1]>=0;j++)
            arr[j]=arr[j-2]-arr[j-1];
        if(max<j){
            max = j;
            for(int k=0;k<max;k++)res[k] = arr[k];
        }
    } 
    printf("%d\n",max);
    for(int i=0;i<max;i++)printf("%d ",res[i]);
    return 0;
}
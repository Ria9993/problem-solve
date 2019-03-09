#pragma warning(disable:4996)
#include <stdio.h>

void swap(int *x,int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int arr[10000]={0.};
    int n;
    int cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]<arr[j]) {
                swap(&arr[i],&arr[j]);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
	return 0;
}
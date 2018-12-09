#include <stdio.h>

void  shellSort (int *arr, int  n);
void  shellSort (int *arr, int  n, int  k);
void selectSort (int *arr, int  n);
void   printArr (int *arr, int  n);
void       swap (int *x  , int *y);

int main() {
    int n, arr[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);

    printArr(arr,n);
    shellSort(arr,n);
    return 0;
}

void shellSort(int *arr,int n) {
    int k;
    for(k=1;k<n;k=k*3+1);
    shellSort(arr,n,k/3);
}
void shellSort(int *arr,int n,int k) {
    if(k==0)return;
    int tmpArr[50],cnt=0;
    for(int c=0;c<k;c++,cnt=0) {
        for(int i=c;i<n;i+=k)tmpArr[cnt++] = arr[i];
        selectSort(tmpArr,cnt);
        for(int i=c,j=0;i<n;i+=k,j++)arr[i] = tmpArr[j];
        printArr(arr,n);
    }
    shellSort(arr,n,k/3);
}
void selectSort(int *arr,int n) {
    int min=0;
    for(int i=0;i<n;i++,min=i) {
        for(int j=i;j<n;j++) {
            if(arr[j]<arr[min]) min=j;
        }
        if(arr[min]!=arr[i])
            swap(&arr[min],&arr[i]);
    }
}
void printArr(int *arr,int n) {
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    printf("\n");
}
void swap(int *x,int *y) {if(*x!=*y) *x^=*y^=*x^=*y;}
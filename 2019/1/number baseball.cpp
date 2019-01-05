#include <stdio.h>

//typedef struct
int wei[11]={-111,0,};
int arr[101][6]={0,};
int main(){
    int n;
    int res=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%1d %1d %1d",&arr[i][0],&arr[i][1],&arr[i][2]);
        scanf("%d %d",&arr[i][3],&arr[i][4]);
    }
    int s=0,b=0,tmp=0;
    for(int i=1;i<10;i++) {
        for(int j=1;j<10;j++) {
            for(int k=1;k<10;k++) {
                s=0,b=0,tmp=0;
                for(int p=0;p<n;p++) {
                    if(arr[p][0]==i) s++;
                    if(arr[p][1]==j) s++;
                    if(arr[p][2]==k) s++;
                    if(arr[p][1]==i||arr[p][2]==i) b++;
                    if(arr[p][0]==j||arr[p][2]==j) b++;
                    if(arr[p][0]==k||arr[p][1]==k) b++;
                    if(arr[p][3]==s&&arr[p][4]==b) tmp++;
                }
                if(tmp==n)res++;
            }
        }
    }
    printf("%d",res);
    return 0;
} 

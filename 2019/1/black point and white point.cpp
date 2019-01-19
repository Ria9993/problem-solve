#include <stdio.h>

int main() {
    int n;
    bool arr[1000]={0,};
    bool flag[1000]={false,};
    int line[1000] = {0,};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%1d",&arr[i]);

    for(int i=1;i<n;i++) {
        for(int j=1;j+i<=n;j++) {

            if(arr[j]!=arr[j+i] && flag[j]  ==false &&
                                   flag[j+i]==false) {
            flag[j]=flag[j+i]=true;
            line[j] = j+i;                
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d %d \n",i,line[i]);
}
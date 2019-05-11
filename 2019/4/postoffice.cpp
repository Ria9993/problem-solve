#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int N,M,vil[501][2]={0,},post[501];
int lenMax=0,res=0;
int main() {
    memset(vil,0,sizeof(vil));
    scanf("%d %d",&N,&M);
    for (int i=0;i<N;i++)scanf("%d",&vil[i][0]);
    lenMax = (vil[N-1][0]-vil[0][0])/M;
    for(int i=0,j;i<N;i++) {
        for(j=i;j==i||(vil[j][0]-vil[i][0])/(j-i+1)<(vil[j-1][0]-vil[i][0])/(j-i);j++);
        for(int k=abs(j-i);k<N;k++) {
            
        }
        for(int k=i;k<j;k++) {
            for(int l=i;l<j;l++) {
                if(k!=l)vil[l][1]+=abs(vil[k][0]-vil[l][0]);
            }
        }
        int minn=-1;
        for(int k=i;k<j;k++)if(minn==-1||vil[minn][1]<vil[k][1])minn=k;
        res+=vil[minn][1];
        i = j;
    }
    for(int i=0;i<N;i++) printf("%d ",vil[i][1]);
    printf("\n%d",res);
    return 0;
}
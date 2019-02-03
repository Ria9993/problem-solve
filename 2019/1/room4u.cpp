//ing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct sc{
    int s;
    int e;
    int v;
}sc;
bool vsort(sc x,sc y){return x.v>y.v;}
int main() {
    int n;
    int flag[1000]={false,};
    int tflag[510]={0,};
    int cnt=0;
    sc sch[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&sch[i].s,&sch[i].e);
        sch[i].v = abs(sch[i].s-sch[i].e);
    }
    sort(sch,sch+n,vsort);
    for(int i=0;i<n;i++) {
        int fl=false;
        for(int j=sch[i].s;j<sch[i].e;j++)if(flag[j])fl=i;
        if(fl) {
            
        }
        else {
            for(int j=sch[i].s;j<sch[i].e;j++)flag[j]=i;
            cnt++;
        }
    }  
    printf("%d",cnt);
    return 0;
}
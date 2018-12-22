#include <stdio.h>
#include <algorithm>
#define _max(x,y) x<y?(x):(y)
#define INF 200
using namespace std;
int mmx=0,g[INF][INF]={0,},chk[INF]={0,},res[INF][INF],rest[INF];
int mmax=INF,mmin=0;
int f(int x,int y,int cnt) {
    chk[x] = false;
    res[y][cnt]=x;
    for(int i=0;i<=mmx;i++) {
        if(g[x][i]&&chk[i]) return 1+f(i,y,cnt+1);
    }
    return 0;
}
int main() { //kl
    int x=0,y=0,i,j;
    int tmp_min,tmp_max;
    for(int i=0;x==100||y==100;i++) {
        scanf("%d %d",&x,&y);
        mmx=_max(mmx,_max(x,y));
        g[x][y]=g[y][x]=true;
        chk[x]=chk[y]=true;
    }
    for(i=1,j=0;i<100;i++) {
        if(chk[i]) {
            int tmp = f(i,j,0);
            if(mmin > tmp) {
                mmin = tmp;
                tmp_min = j;
            }
            if(mmax > tmp) {
                mmax = tmp;
                tmp_max = j;    
            }
            j++;
        }
    }
    if(j==1) {
		for (i = 0; i < mmax; i++)
            rest[i] = res[0][i];
        sort(rest,rest+mmax);
        for(i =0;i<mmax;i++) printf("%d ",rest[i]);
    }
    else {
		for (j = 0; j < mmin; i++, j++)
			rest[i] = res[tmp_min][j];
		for (i = 0, j = 0; j < mmax; i++, j++)
			rest[i] = res[tmp_max][j];
		sort(rest, rest + (mmin + mmax));
		for (i = 0; i < (mmin + mmax); i++) printf("%d ", rest[i]);
    }
    return 0;
}   
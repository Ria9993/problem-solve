#pragma warning(disable:4996)
#include <stdio.h>
int n,map[1000][1000];
int memo[1000][1000]={0,};
void f(int x,int y,int sum) {
    sum+=map[x][y];
    if(sum>memo[x][y]|| memo[x][y]==0) {
        memo[x][y]=sum;
        if(x<n&&y<n) {
            f(x+1,y,sum);
            f(x,y+1,sum);
        }
    }
}
void rev(int x,int y) {
    if(x==0&&y==0)return; //last
    if(memo[x-1][y]>memo[x][y-1]) {
        rev(x-1,y);
        printf("D\n");
    }
    else {
        rev(x,y-1);
        printf("R\n");
    }
}
int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&map[i][j]);
    }
    f(0,0,0);
    printf("%d\n",memo[n-1][n-1]);
    rev(n-1,n-1);
    return 0;
}
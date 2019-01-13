#include <stdio.h>

int main() {
    int p1,p2,n,now;
    int tmp,next=1;
    int l[1000],cnt=0;
    scanf("%d %d %d",&p1,&p2,&n);
    for(;p1<=p2;p1++) {
        now=p1,tmp=1;
        while(now/10!=0)for(;now!=0;now/10)tmp*=now%10;now=tmp;
        if(now==n)l[cnt++]=p1;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)printf("%d\n",l[cnt]);
    return 0;
}
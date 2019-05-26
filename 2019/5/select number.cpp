#pragma warning(disable:4996)
#include <stdio.h>
#define SP 2
#define CHAIN 3
int n,cnt=0,arr[100010],chk[100010];
bool f(int idx) {
    if(arr[idx]==idx&&chk[idx]==SP) return chk[idx]=CHAIN;
    if(chk[arr[idx]]==SP)return chk[idx]=CHAIN; //완성되면 튀어
    if(chk[idx]==CHAIN||chk[idx]==true)return false;
    if(chk[idx]!=SP)chk[idx]=true;
    if(f(arr[idx])==false) return chk[idx]=false;
    else return chk[idx]=CHAIN;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) if(chk[i]==false) {chk[i]=SP;f(i);}
    for(int i=1;i<=n;i++) if(chk[i]==CHAIN) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++) if(chk[i]==CHAIN) printf("%d\n",i);
    return 0;
 }
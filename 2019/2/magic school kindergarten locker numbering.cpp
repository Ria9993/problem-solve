#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct _xy{
    int x;
    int y;
}_xy;
bool cm(_xy x,_xy y){if(x.x==y.x)return x.y<y.y;return x.x<y.x;}
_xy xy[1000];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&xy[i].x);
        xy[i].y=i;
    }   
    sort(xy,xy+n,cm);
    for(int i=0;i<n;i++)
        printf("%d ",xy[i].y+1);
    return 0;
}
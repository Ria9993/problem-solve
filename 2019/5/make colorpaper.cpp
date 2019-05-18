#pragma warning(disable:4996)
#include <stdio.h>
#define half ((ed.y-st.y)/2)
int n,map[200][200]={0,};
typedef struct _xy{
    int x;
    int y;
}_xy;
_xy f(_xy st,_xy ed) {
    _xy wb = {0,0},tmp; 
    int i=st.x,j=st.y,flag=map[st.x][st.y];
    if(st.x==ed.x-1&&st.y==ed.y-1) 
        return {map[st.x][st.y]?0:1,map[st.x][st.y]?1:0};
    for(;i<ed.x;i++) {
        for(;j<ed.y;j++) {
            if(map[i][j]!=flag) {
                tmp=f(st,{st.x+half,st.y+half});          wb={wb.x+tmp.x,wb.y+tmp.y};
                tmp=f({st.x,st.y+half},{st.x+half,ed.y}); wb={wb.x+tmp.x,wb.y+tmp.y};
                tmp=f({st.x+half,st.y},{ed.x,st.y+half}); wb={wb.x+tmp.x,wb.y+tmp.y};
                tmp=f({st.x+half,st.y+half},ed);          wb={wb.x+tmp.x,wb.y+tmp.y};
                return wb;
            }
        }
    }
    return {map[st.x][st.y]?0:1,map[st.x][st.y]?1:0};
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&map[i][j]);
    }
    _xy res=f({0,0},{n,n});
    printf("%d\n%d",res.x,res.y);
    return 0;
}
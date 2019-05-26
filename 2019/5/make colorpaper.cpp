#include <stdio.h>
int n,map[200][200]={0,};
typedef struct _xy{int x;int y;}_xy;
void add(_xy *x,_xy y) {x->x+=y.x;x->y+=y.y;}
_xy f(_xy st,int len) {
    _xy wb = {0,0};
    int flag=map[st.x][st.y];
    if(len==1) return {map[st.x][st.y]?0:1,map[st.x][st.y]?1:0};
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            if(map[st.x+i][st.y+j]!=flag) {
                add(&wb,f(st,len/2));
                add(&wb,f({st.x,st.y+len/2},len/2));
                add(&wb,f({st.x+len/2,st.y},len/2));
                add(&wb,f({st.x+len/2,st.y+len/2},len/2));
                return wb;
            }
    return {map[st.x][st.y]?0:1,map[st.x][st.y]?1:0};
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&map[i][j]);
    _xy res=f({0,0},n);
    printf("%d\n%d",res.x,res.y);
    return 0;
}
#include <stdio.h>

typedef struct _addr {
    int addr;
    int value;
}_addr;
typedef struct _pair {
    _addr x;
    _addr y;
}_pair;

int main() {
    _pair pair[100];
    _addr num[100][100];
    int cnt[100]={0,};
    int n=0;
    for(int i=0;pair[i-1].x.value==100||pair[i-1].y.value==100;i++,n++) {
        scanf("%d %d",&pair[i].x,&pair[i].y);
        num[pair[i].x.value][cnt[pair[i].x.value]]={i,num[pair[i].x.value][cnt[pair[i].x.value]].value+1};    
        
    }
    
    return 0;
}
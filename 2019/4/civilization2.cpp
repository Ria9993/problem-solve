#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef struct _xy {
    int x;
    int y;
}_xy;
_xy civ[100010];
_xy stack[4000010];
_xy subStack[4000010];
int top=0,int subTop=0;

int map[2010][2010]={0,};
int mapSize,num;

void push(int y,int x) {
    if(y<0||y>=mapSize||x<0||x>=mapSize) return;
    subStack[top++] = {y,x};
}
_xy pop() {return stack[top--];}
void subCpy() { //sub to main
    top = subTop;
    for(int i=0;i<subTop;i++)
        stack[i] = subStack[i];
    subTop=0;
}

int main() {
    scanf("%d %d",mapSize,num);
    for(int i=0;i<num;i++) {
        scanf("%d %d",civ[i].y,civ[i].x);
        push(civ[i].y,civ[i].x);
    }
    for(int res=0;;res++) {
        subCpy();
        while(top) {
            _xy now = pop();
            bfs(now.y,now.x);
        }
        
    }
    return ;
}
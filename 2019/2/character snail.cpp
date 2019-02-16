#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
int xp[2][4]={{1,0,-1,0},{0,1,0,-1}};
int yp[2][4]={{0,1,0,-1},{-1,0,1,0}};

int main() {
    int map[10][10]={0,};
    int n;
    char mod,s;

    scanf("%d",&n);
    scanf("%c",&mod);
    if(mod=='R') mod=0;
    else mod=1;

    scanf("%c",&s);
    int now=isspace(s)?s-'A':s;

    

    return 0;
}
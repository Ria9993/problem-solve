#include <stdio.h>
#include <stdlib.h>

typedef enum _OP{
    S = 0,
    X = 1
}_OP;
_OP OP[100010];
int opCnt=0;
int n,m,cnt=1;
int queue[100010]={0,},top=0;

void push(int n) {queue[top++]=n;}
int  pop()       {return queue[--top];}
int  view()      {return queue[top-1];}
void sp(_OP n)   {OP[opCnt++]=n;}
int main() {
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&m);
             if (cnt==m)      {sp(S);sp(X); cnt++;  }
        else if (i==0)        {sp(S);       push(m);}
        else if (view()==cnt) {sp(X);       pop();cnt++;
                               while(view()==cnt){sp(X);pop();cnt++;}
                               sp(S);push(m);}
           else               {sp(S);       push(m);}
    }
    while(top) {
		if (queue[--top] != cnt++) { printf("IMPOSSIBLE"); exit(0); }
        else sp(X);
    }
	for (int i = 0; i < opCnt; i++)printf("%c", "SX"[OP[i]]);
    return 0;
}
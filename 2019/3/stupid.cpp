#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct _st{
    char name[10];
    int val;
}_st;
_st stu[10000];
bool cmp(_st x,_st y) {return x.val<y.val;}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s %d",stu[i].name,&stu[i].val);
    }
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct _gold{
	int w;
	int c;
	float m;
}_gold;
_gold gold[50000];
bool cmp(_gold x,_gold y) {return x.m>y.m;}
int main() {
	int n,m, now=0;
	double res=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&gold[i].w,&gold[i].c);
		gold[i].m = (float)gold[i].c/gold[i].w;
	}
	sort(gold,gold+n,cmp);
	for(int i=0;now<m;i++) {
		if(now+gold[i].w<=m){now+=gold[i].w;res+=gold[i].w*gold[i].c;}
		else {
			for(int j=gold[i].w;j>0;j--) {
				if(now+j<=m){now+=j;res+=j*gold[i].c;}
			}
		printf("%.0lf",res);
		return 0;
		}
	}
	printf("%.0lf",res);
	return 0;
}
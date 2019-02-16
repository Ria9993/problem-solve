#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main() { 	
	char n[210], m[210], res[100010] = { 0, };
	int cnt = 0, tmp;
	char *a,*b;
	scanf("%s %s", n, m);
    
	if (strlen(n) < strlen(m)) *a = *m,*b = *n;
	else *a = *n,*b = *m;
	for(int i=0;i<strlen(a);i++) a[i]-='0';
	for(int i=0;i<strlen(b);i++) b[i]-='0';

	for(int i=strlen(a)-1;i>=0;i--) {
		int sum=0;
		for(int j=strlen(b)-1;j>=0;j++) {
			sum+=a[i]*b[j];
			res[cnt++]+=sum%10;
			sum/=10;
		}
		res[cnt]+=sum;
		cnt=strlen(a)-i;
	}
	strrev(res);
	for(int i=0;i<strlen(res);i++)printf("%d",res[i]);
	return 0;
}
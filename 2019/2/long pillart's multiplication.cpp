#include <stdio.h>
#include <string.h>

int main() {
    char n[210],m[210],res[100010]={0,};
    int cnt=0,tmp;
    scanf("%s %s",n,m);
    for(int i=strlen(n);i>=0;i--) {
        n[i]-='0';
        for(int j=strlen(m);j>=0;j--) {
            m[j]-='0';
            tmp=n[i]*m[i]/10;
            res[cnt++]+=n[i]*m[i]%10;
            res[cnt]+=tmp;
        }
        printf("%s\n",res);
    }
    return 0;
}
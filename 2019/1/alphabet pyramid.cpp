#include <stdio.h>
#include <ctype.h>

int main() {
    int n;
    char ab;
    scanf("%c",&ab);
    scanf("%d",&n);
    if(!isupper(ab)||n>24) printf("입력에러!");
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++)printf(" ");
        for(int j=1;j<=((i-1)*2)+1;j++) {
            printf("%c",ab++);
            if(ab>'Z')ab='A';
        }
        printf("\n");
    }
    return 0;
}
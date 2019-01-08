#include <stdio.h>
void f(int n, int now, char *str, int len) {
   if (len) { //맨처음 함수들어왓을때 씹음
      str[len] = now;
      for (int i = 1; i <= len; i++) printf("%c", str[i]+'a'-1);
      printf("\n");
   }
   for (int i = now + 1; i <= n; i++) f(n, i, str, len + 1);
}
int main() {
   char str[101] = { 0, };
   int n;
   scanf("%d", &n);
   f(n, 0, str, 0);
   return 0;
}
#include<stdio.h>
long long int A[10][2005];
int main() {
   long long int n, m, i, j, k, p = 1;
   scanf("%lld %lld", &n, &m);
   k = m;
   for (i = n - 1; i >= 0; i--) {
      A[i][k + 1] = -1;
      k /= 2;
   }
   for (i = 1; i <= m; i++) {
      if (A[0][i] == -1)
         break;
      A[0][i] = 1;
   }
   for (i = 1; i < n;) {
      for (j = p; j <= m; j++) {
         if (A[i][j] == -1)
            break;
         for (k = j * 2; k <= m; k++) {
            if (A[i][k] == -1)
               break;
            A[i][k]+= A[i-1][j];
         }
      }
      i++;
      p *= 2;
   }
   long long int sum = 0;
   for (i = 1; i <= m; i++)
      sum += A[n - 1][i];
   printf("%lld", sum);
}
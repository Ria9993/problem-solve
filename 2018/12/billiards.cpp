#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return (x * (y / gcd(y, x))); }
char re[6] = { "WESN" };
int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n, m;
   int x = 0, y = 0;
   int cnt = 0, arr[10000];
   scanf("%d %d", &n, &m);
   int size = lcm(n, m);
   int xflag = 0;
   int yflag = 0;
   for (int i = 0;; i++) {
      if (i) {
         if (x == size && y == size) {
			  printf("%d\n", cnt); for (int j = 0; j < cnt; j++)printf("%c ", re[arr[j] - 1]); printf("3"); return 0; }//3
         else if (x == size * 2 && y == size) {
			  printf("%d\n", cnt); for (int j = 0; j<cnt; j++)printf("%c ", re[arr[j] - 1]); printf("4"); return 0; }//4
         else if (x == size && y == size * 2) {
			  printf("%d\n", cnt); for (int j = 0; j < cnt; j++)printf("%c ", re[arr[j] - 1]); printf("2"); return 0; }//2
         else if (x == size * 2 && y == size * 2) {
			  printf("%d\n", cnt); for (int j = 0; j<cnt; j++)printf("%c ", re[arr[j] - 1]); printf("1"); return 0; }//1

         if (x >= size * 2) { x = x % size; arr[cnt++] = 1; xflag = 0; }//1 w
         if (x >= size&&xflag==0) {
            arr[cnt++] = 2;
            xflag = 1;
         } //2 e
         if (y >= size * 2) { y = y % size; arr[cnt++] = 3; yflag = 0; }//3 s
         if (y >= size&&yflag==0) {
            arr[cnt++] = 4;
            yflag = 1;
         }//4 n

      }
      y += n;
      x += m;
   }
   return 0;
}
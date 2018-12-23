#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int queue[1010] = { 0, }, top = 0, tail = 0;
void push(int n) { queue[top++] = n; }
int pop() { return queue[tail++]; }
int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
   int n, x, cnt = 1;
   scanf("%d", &n);
   for (int i = 0; i<n || (top != tail || i<n); i++) {
      if (i<n)scanf("%d", &x);
      if (cnt == x) cnt++;
      else if (cnt == queue[tail] && i >= n) {
         pop(); cnt++;
      }
      else if (cnt == queue[tail]) {
         if (x == cnt + 1)cnt++;
         else push(x); 
         pop(); cnt++;
      }
      else if (i<n) push(x);
      else break;
   }
   if (tail == top) printf("YES");
   else printf("NO");
   return 0;
}
//1 4 2 3 5
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct zz {
  int x, y;
}zz;
zz rm[1000];
bool sr(zz a, zz b) {
  if (a.y == b.y)return a.x < b.x;
  return a.y < b.y;
}
int main() {
  int a, cnt = 0,cc=0,ii=0;
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
     scanf("%d %d", &rm[i].x, &rm[i].y);
  }
  sort(rm, rm + a, sr);
  for (int i = 0; i < a; i++) {
     if (rm[i].x >= ii) {
        ii = rm[i].y, cnt++;
     }
  }
  printf("%d", cnt);
}
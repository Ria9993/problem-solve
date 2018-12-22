#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return (x * (y / gcd(y, x))); }
int main() {
    int n,m;
    int x,y;
    scanf("%d %d",&n,&m);
    int size=lcm(n,m);
    for(int i=0;;i++) {
        if(i) {
            if(x==size&&y==size){printf("3");break;}//3
            else if(x==size*2&&y==size){printf("4");break;}//4
            else if(x==size&&y==size*2){printf("2");break;}//2
            else if(x==size*2&&y==size*2){printf("1");break;}//1
            if(x>=size*2) {x=x%size;printf("W ");}
            if(x>=size) {printf("E ");}
            if(y>=size*2) {x=x%size;printf("N ");}
            if(y>=size) {printf("S ");}

        }
        y+=n;
        x+=m;
    }
	return 0;
}
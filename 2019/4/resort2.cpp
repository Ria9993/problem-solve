#pragma warning(disable:4996)
#include <stdio.h>
int mem[105][41]={0,}; //mem[날짜][쿠폰수]
int day[105]={false,}; //안가도 되는날
int N,M,tmp;
void f(int n,int cost,int coupon) {
    if(n>N+1||(mem[n][coupon]<cost&&mem[n][coupon]))return;
    if(day[n]){f(n+1,cost,coupon);return;}
    mem[n][coupon]=cost;
    f(n+5,cost+37000,coupon+2); 
    f(n+3,cost+25000,coupon+1);
    if(coupon>=3)f(n+1,cost,coupon-3);
    else f(n+1,cost+10000,coupon);
}
int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){scanf("%d",&tmp);day[tmp]=true;}
    f(1,0,0);
    int min=-1;
    for(int i=0;i<41;i++)
        if((mem[N+1][min]>mem[N+1][i]&&mem[N+1][i]!=0)||min==-1||mem[N+1][min]==0)
            min=i;
    printf("%d",mem[N+1][min]);
    return 0;
}

/*
int f(int day, int coupon) { 
    if (day > N) return 0; if (dp[day][coupon] == -1) dp[day][coupon] = chk[day] ? f(day + 1, coupon) : min({coupon >= 3 ? f(day + 1, coupon - 3) : f(day + 1, coupon) + 10000, f(day + 3, coupon + 1) + 25000, f(day + 5, coupon + 2) + 37000}); return dp[day][coupon]; } 
*/
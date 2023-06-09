#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL dp[202][202][202];
int blue[202],green[202],red[202];
LL DP(int r,int g,int b)
    if((!r && !g)  ||  (!r && !b)  ||  (!b && !g))return 0;
    if(dp[r][g][b])return dp[r][g][b];
    LL ans=0;
    if(r && g)ans=max(ans,red[r]*green[g]+DP(r-1,g-1,b));
    if(r && b)ans=max(ans,red[r]*blue[b]+DP(r-1,g,b-1));
    if(b && g)ans=max(ans,blue[b]*green[g]+DP(r,g-1,b-1));
    return dp[r][g][b]=ans;
int main()
    FAST();
    int i,r,g,b;
    cin >> r >> g >> b;
    for(i=1;i<=r;i++)cin >> red[i];
    for(i=1;i<=g;i++)cin >> green[i];
    for(i=1;i<=b;i++)cin >> blue[i];
    sort(red+1,red+r+1);
    sort(green+1,green+g+1);
    sort(blue+1,blue+b+1);
    cout << DP(r,g,b);
    return 0;
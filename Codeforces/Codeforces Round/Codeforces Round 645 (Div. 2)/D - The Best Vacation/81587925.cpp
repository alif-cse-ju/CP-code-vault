#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int n;
LL days[400005],hugs[400005];
LL FindOpt(LL val)
    int idx=upper_bound(days,days+2*n+1,val)-days-1;
    val-=days[idx];
    return hugs[idx]+(val*(val+1))/2;
int main()
    FAST();
    int i;
    LL x,y,ans=0;
    cin >> n >> y;
    for(i=1;i<=n;i++)
    {
        cin >> days[i];
        days[n+i]=days[i];
    }
    for(i=1;i<=2*n;i++)
    {
        hugs[i]=hugs[i-1]+(days[i]*(days[i]+1))/2;
        days[i]+=days[i-1];
    }
    for(i=0;i<n;i++)
    {
        x=days[i];
        ans=max(ans,FindOpt(x+y)-FindOpt(x));
    }
    for(i=n+1;i<=2*n;i++)
    {
        x=days[i];
        ans=max(ans,FindOpt(x)-FindOpt(x-y));
    }
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    map<int,int>mp;
    int i,n,x,ans=0,posa[200005],posb[200005];
    cin >> n;
    for(i=1;i<=n;i++)cin >> x,posa[x]=i;
    for(i=1;i<=n;i++)cin >> x,posb[x]=i;
    for(i=1;i<=n;i++)
    {
        if(posa[i] >= posb[i])++mp[posa[i]-posb[i]];
        else ++mp[n-posb[i]+posa[i]];
    }
    for(auto it : mp)ans=max(ans,it.second);
    cout << ans;
    return 0;
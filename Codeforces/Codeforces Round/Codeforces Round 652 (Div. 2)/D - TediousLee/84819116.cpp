#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
pair<LL,int>ans[2000002];
int main()
    FAST();
    int i,n,t;
    LL mod=1e9+7;
    ans[3]={4,1};
    for(i=4;i<=2000000;i++)
    {
        ans[i].first=(ans[i-1].first+ans[i-2].first*2LL)%mod;
        if(!ans[i-1].second  &&  !ans[i-2].second)
        {
            ans[i].first+=4LL;
            if(ans[i].first >= mod)ans[i].first-=mod;
            ans[i].second=1;
        }
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ans[n].first << '\n';
    }
    return 0;
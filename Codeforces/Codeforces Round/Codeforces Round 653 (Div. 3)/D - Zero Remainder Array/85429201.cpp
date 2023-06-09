#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int n,t;
    LL k,x,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> k;
        map<LL,int>mp;
        while(n--)
        {
            cin >> x;
            if(x%k == 0)continue;
            x=k-x%k;
            ans=max(ans,k*mp[x]+x+1);
            ++mp[x];
        }
        cout << ans << '\n';
    }
    return 0;
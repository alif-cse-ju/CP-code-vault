#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll ans,m,mn,n,tmp,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        if(m == 1ll)ans=(n-1)*x;
        else if(n == 1ll)ans=(m-1)*x;
        else
        {
            ans=(m+n-2)*x;
            mn=min(m,n);
            m-=mn,n-=mn;
            tmp=(mn-1)*y;
            ans=min(ans,tmp+(m+n)*x);
            if(m & 1)tmp+=x,--m;
            if(n & 1)tmp+=x,--n;
            tmp += (m+n)*y;
            ans=min(ans,tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}
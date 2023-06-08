#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
ll a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=a[i];j<=2*n;j+=a[i])
            {
                k=j-i;
                if(k > i  &&  k <= n  &&  a[i]*a[k] == j)++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
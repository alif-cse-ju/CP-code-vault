#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
int cnt[60];
long long a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t;
    long long ans,_and,_or;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            for(j=0;j<60;j++)cnt[j]+=((a[i] >> j) & 1);
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            _and=_or=0;
            for(j=0;j<60;j++)
            {
                if((a[i] >> j) & 1)
                {
                    _or=(_or+((1LL << j)%mod)*n)%mod;
                    _and=(_and+((1LL << j)%mod)*cnt[j])%mod;
                }
                else _or=(_or+((1LL << j)%mod)*cnt[j])%mod;
            }
            ans=(ans+_and*_or)%mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long a,b,k,m,n,ans;
    cin >> n >> k >> a >> b;
    if(k == 1)cout << a*(n-1);
    else
    {
        ans=0;
        while(n > 1)
        {
            m=(n/k)*k;
            if(m == 0)++m;
            ans+=(n-m)*a;
            n=m;
            if(n == 1)break;
            if(b < (n-n/k)*a)ans+=b,n/=k;
            else
            {
                ans+=(n-1)*a;
                break;
            }
        }
        cout << ans;
    }
    return 0;
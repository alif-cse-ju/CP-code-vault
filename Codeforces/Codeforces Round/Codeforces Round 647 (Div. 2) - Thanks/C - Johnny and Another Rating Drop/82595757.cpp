#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL n,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        while(n > 0)
        {
            x=1;
            while(x <= n)ans+=x,x*=2;
            x/=2;
            n-=x;
        }
        cout << ans << '\n';
    }
    return 0;
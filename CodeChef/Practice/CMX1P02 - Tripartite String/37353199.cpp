#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t;
    LL x,r,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> ans;
        for(i=1;i<n;i++)
        {
            cin >> x;
            ans=(ans*x)/__gcd(ans,x);
        }
        cin >> r;
        cout << ans+r << '\n';
    }
    return 0;
}
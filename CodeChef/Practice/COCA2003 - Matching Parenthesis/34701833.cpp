#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL ans[100005];
int main()
{
    FAST();
    int n,t;
    LL i,mod=1e9+7;
    ans[0]=1;
    for(i=1;i<100001;i++)ans[i]=(((ans[i-1]*i)%mod)*(2*i-1))%mod;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,n,ans,cnt1,cnt2,cnt3,mod=1e9+7;
    cin >> n;
    if(n == 1)cout << 0;
    else
    {
        cnt1=cnt2=cnt3=1;
        for(i=1;i<=n;i++)
        {
            cnt1=(cnt1*10)%mod;
            cnt2=(cnt2*9)%mod;
            cnt3=(cnt3*8)%mod;
        }
        ans=(cnt1+cnt3-2*cnt2)%mod;
        cout << (ans+mod)%mod;;
    }
    return 0;
}

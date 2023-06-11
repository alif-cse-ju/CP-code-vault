#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    LL ans;
    int n,t,x,sum,mod=1e9;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=ans=0;
        map<int,int>mp;mp[0]=1;
        while(n--)
        {
            cin >> x;
            sum=(sum+x)%mod;
            ans+=mp[sum],++mp[sum];
        }
        cout << ans << '\n';
    }
    return 0;
}
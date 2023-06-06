#include<bits/stdc++.h>

using namespace std;

const int N=5e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool mark[52]={0};
    int i,j,l,n,a[52];
    long long ans=LLONG_MAX,val;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    vector<int>v;
    v.emplace_back(2);
    for(i=3;i<50;i+=2)
    {
        if(!mark[i])
        {
            v.emplace_back(i);
            for(j=i*i;j<50;j+=2*i)mark[j]=1;
        }
    }
    l=(int)v.size();
    for(i=1;i<(1 << l);i++)
    {
        val=1;
        for(j=0;j<l;j++)
        {
            if((i >> j) & 1)val*=v[j];
        }
        for(j=1;j<=n;j++)
        {
            if(__gcd(1ll*a[j],val) == 1ll)break;
        }
        if(j > n)ans=min(ans,val);
    }
    cout << ans;
    return 0;
}
//
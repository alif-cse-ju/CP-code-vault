#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
ll fact[M],pw[M];
ll BigMod(ll val,ll pow)
    ll res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
void PreCal()
    fact[0]=pw[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod,pw[i]=(2ll*pw[i-1])%mod;
}
 ll nCr(int n,int r)
{
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,tmp1,tmp2;
    int i,k,n,t;
    cin >> t;
    PreCal();
    while(t--)
    {
        cin >> n >> k;
        if(n & 1)
        {
            ans=2;
            for(i=2;i<n;i+=2)ans=(ans+nCr(n,i))%mod;
            ans=BigMod(ans,k);
        }
        else
        {
            ans=tmp1=tmp2=0;
            for(i=1;i<n;i+=2)tmp1=(tmp1+nCr(n,i))%mod;
            for(i=0;i<n;i+=2)tmp2=(tmp2+nCr(n,i))%mod;
            for(i=1;i<=k;i++)ans=(ans+((BigMod(tmp2,k-i)*tmp1)%mod*BigMod(pw[n],i-1))%mod)%mod;
            ans=BigMod(BigMod(2,n),k)-ans;
            if(ans < 0)ans+=mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
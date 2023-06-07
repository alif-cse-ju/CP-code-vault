#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int n,sum[M][32];
ll fact[M],invFact[M];
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
void Fact()
{
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
    for(int i=0;i<M;i++)invFact[i]=BigMod(fact[i],mod-2)%mod;
}
 ll nCr(int n,int r)
{
    ll tmp=(invFact[r]*invFact[n-r])%mod;
    return (fact[n]*tmp)%mod;
}
 void Update(int i,int b,int v)
{
    while(i <= n)sum[i][b] += v, i += (i & -i);
}
 int Query(int i,int b)
{
    int ans=0;
    while(i)ans += sum[i][b], i -= (i & -i);
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll all,ans,tmp,v;
    int _0,_1,i,j,l,m,r,t,x;
    Fact();
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<30;j++)sum[i][j]=0;
        }
        while(m--)
        {
            cin >> l >> r >> x;
            for(i=0;i<30;i++)
            {
                if(!((x >> i) & 1))Update(l,i,1), Update(r+1,i,-1);
            }
        }
        ans=0, all=BigMod(2,n);
        for(i=0;i<30;i++)
        {
            _0=_1=0;
            for(j=1;j<=n;j++)
            {
                x=Query(j,i);
                if(x)++_0;
                else ++_1;
            }
            v=BigMod(2,_0), tmp=all;
            for(j=0;j<=_1;j+=2)tmp-=(v*nCr(_1,j)), tmp %= mod;
            tmp=(tmp*(1ll << i))%mod;
            ans=(ans+tmp)%mod;
        }
        if(ans < 0)ans += mod;
        cout << ans << '\n';
    }
    return 0;
}
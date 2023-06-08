#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
ll fact[M];
void Fact()
    fact[0]=1;
    for(int i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
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
}
 ll nCr(int n,int r)
{
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}
 void Solve()
{
    int i,n,x;
    cin >> n;
    vector<int>v;
    map<int,int>mp;
    for(i=0;i<n;i++)
    {
        cin >> x;
        ++mp[x];
    }
    ll ans,tmp;
    ans=tmp=fact[n];
    for(auto [x,y] : mp)v.emplace_back(x);
    n=(int)v.size();
    if(mp[v[n-1]] > 1)
    {
        cout << ans << '\n';
        return;
    }
    if(v[n-1] > v[n-2]+1)
    {
        cout << "0\n";
        return;
    }
    v.clear();
    for(auto [x,y] : mp)v.emplace_back(y);
    reverse(v.begin(),v.end());
    tmp=(tmp*BigMod(v[1]+1,mod-2))%mod;
    ans-=tmp;
    if(ans < 0)ans+=mod;
    cout << ans << '\n';
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    Fact();
    while(t--)Solve();
    return 0;
}
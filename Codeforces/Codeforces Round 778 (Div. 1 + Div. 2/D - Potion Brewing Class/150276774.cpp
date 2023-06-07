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
const int N=2e6+5;
const int mod=998244353;
ll ans[M];
int cnt[M],mark[M],mn[M];
vector<tuple<int,int,int>>adj[M];
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
}
 void Sieve()
{
    for(int i=2;i<M;i++)
    {
        if(!mark[i])
        {
            for(int j=i;j<M;j+=i)
            {
                if(!mark[j])mark[j]=i;
            }
        }
    }
}
 void DFS(int x,int p)
{
    int tmp;
    for(auto [y,c,d] : adj[x])
    {
        if(p ^ y)
        {
            tmp=d;
            while(tmp > 1)++cnt[mark[tmp]], tmp /= mark[tmp];
             tmp=c;
            while(tmp > 1)
            {
                --cnt[mark[tmp]];
                mn[mark[tmp]]=min(mn[mark[tmp]], cnt[mark[tmp]]);
                tmp /= mark[tmp];
            }
             DFS(y,x);
             tmp=d;
            while(tmp > 1)--cnt[mark[tmp]], tmp /= mark[tmp];
             tmp=c;
            while(tmp > 1)++cnt[mark[tmp]], tmp /= mark[tmp];
        }
    }
}
 void DFS2(int x,int p)
{
    for(auto [y,c,d] : adj[x])
    {
        if(p ^ y)ans[y]=(((ans[x]*d)%mod) * BigMod(c,mod-2))%mod, DFS2(y,x);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum=0;
    int a,b,c,d,i,n,t;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)adj[i].clear(), cnt[i]=mn[i]=0;
        for(i=1;i<n;i++)
        {
            cin >> a >> b >> c >> d;
            adj[a].emplace_back(make_tuple(b,c,d));
            adj[b].emplace_back(make_tuple(a,d,c));
        }
        ans[1]=1;
        DFS(1,0);
        for(i=2;i<=n;i++)ans[1]=(ans[1]*BigMod(i,abs(mn[i])))%mod;
        DFS2(1,0);
        for(i=1, sum=0;i<=n;i++)
        {
            sum += ans[i];
            if(sum >= mod)sum -= mod;
        }
        cout << sum << '\n';
    }
    return 0;
}
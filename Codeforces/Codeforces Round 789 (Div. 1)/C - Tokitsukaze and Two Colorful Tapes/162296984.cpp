#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

int a[M],b[M],sz[M],par[M];

int FindParent(int n)
{
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i], par[i]=i, sz[i]=1;
        for(int i=1;i<=n;i++)
        {
            cin >> b[i];
            int pa=FindParent(a[i]);
            int pb=FindParent(b[i]);
            if(pa != pb)
            {
                if(sz[pa] >= sz[pb])par[pb]=pa, sz[pa] += sz[pb];
                else par[pa]=pb, sz[pb] += sz[pa];
            }
        }
        ll ans=0;
        int l=1, r=n;
        for(int i=1;i<=n;i++)
        {
            if(i == FindParent(i))
            {
                for(int j=0;j<sz[i]/2;j++)ans += r-l, --r, ++l;
            }
        }
        cout << ans+ans << '\n';
    }
    return 0;
}
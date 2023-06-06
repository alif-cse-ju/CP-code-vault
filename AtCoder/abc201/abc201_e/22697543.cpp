#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;

long long xr[N];
vector<pair<int,long long>>adj[N];

void DFS(int x,int par)
{
    for(auto [y,z] : adj[x])
    {
        if(y ^ par)xr[y]=(z ^ xr[x]),DFS(y,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,x,y;
    long long z,ans=0,cnt;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> x >> y >> z;
        adj[x].emplace_back(y,z);
        adj[y].emplace_back(x,z);
    }
    DFS(1,1);
    for(i=0;i<60;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)cnt+=((xr[j] >> i) & 1);
        cnt=(cnt*(n-cnt))%mod;
        ans+=(cnt*((1ll << i)%mod))%mod;
        if(ans >= mod)ans-=mod;
    }
    cout << ans;
    return 0;
}
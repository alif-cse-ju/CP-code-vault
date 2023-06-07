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
const int mod=1e9+7;

int cnt[M];
ll ans[M],sum[M];
vector<pair<int,int>>queries[M];

void Update(int i,int v)
{
    while(i < M)sum[i]+=v, i+=(i & -i);
}

ll Query(int i)
{
    ll ans=0;
    while(i)ans+=sum[i], i-=(i & -i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;cin >> q;
    for(int i=1;i<=q;i++)
    {
        int l,r;cin >> l >> r;
        queries[l].emplace_back(r,i);
    }
    int n=M-5;
    for(int i=n;i;i--)
    {
        for(int j=i+i;j<=n;j+=i)Update(j,cnt[j]), ++cnt[j];
        int l=i;
        for(auto [r,id] : queries[i])
        {
            int sz=r-l+1;
            ll cur=(1ll*sz*(sz-1)*(sz-2))/6;
            cur -= Query(r)-Query(l-1);
            cur -= max(0, r/6-(l+2)/3+1);
            cur -= max(0, r/15-(l+5)/6+1);
            ans[id]=cur;
        }
    }
    for(int i=1;i<=q;i++)cout << ans[i] << '\n';
    return 0;
}
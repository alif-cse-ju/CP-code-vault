#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e5+5;
const int N=1e6+5;
const int mod=1e9+7;
vector<int>adj[N];
int a[N],ans[N],cnt[N];
ordered_set<pair<int,int>>ost;
vector<tuple<int,int,int>>queries[N];
void DFS(int x)
    int small;
    if(cnt[a[x]])ost.erase({cnt[a[x]], a[x]});
    ++cnt[a[x]], ost.insert({cnt[a[x]], a[x]});
    for(int y : adj[x])DFS(y);
    for(auto [l,k,i] : queries[x])
    {
        small=ost.order_of_key({l,0});
        if(small+k > (int)ost.size())ans[i]=-1;
        else
        {
            auto [v,z]=*ost.find_by_order(small+k-1);
            ans[i]=z;
        }
    }
    ost.erase({cnt[a[x]], a[x]});
    --cnt[a[x]]; if(cnt[a[x]])ost.insert({cnt[a[x]], a[x]});
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,n,p,t,q,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i=1;i<=n;i++)cin >> a[i], cnt[i]=0, adj[i].clear(), queries[i].clear();
        for(i=2;i<=n;i++)cin >> p, adj[p].emplace_back(i);
        for(i=1;i<=q;i++)
        {
            cin >> x >> l >> k;
            queries[x].emplace_back(make_tuple(l,k,i));
        }
        ost.clear();
        DFS(1);
        for(i=1;i<=q;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
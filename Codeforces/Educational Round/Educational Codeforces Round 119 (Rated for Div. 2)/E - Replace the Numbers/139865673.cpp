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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int ans[M],par[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n=0,t,q,x,y;
    vector<tuple<int,int,int>>queries;
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)++n, cin >> x, queries.emplace_back(make_tuple(1,x,0));
        else
        {
            cin >> x >> y;
            if(n)queries.emplace_back(make_tuple(2,x,y));
        }
    }
    m=n;
    for(i=1;i<M;i++)par[i]=i;
    while(!queries.empty())
    {
        auto [t,x,y]=queries.back();
        queries.pop_back();
        if(t == 1)ans[m--]=par[x];
        else par[x]=par[y];
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}
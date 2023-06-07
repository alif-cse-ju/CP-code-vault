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
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
vector<int>values[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        map<int,int>cnt;
        for(i=0;i<n;i++)cin >> x, ++cnt[x], values[i].clear();
        map<pair<int,int>,bool>bad;
        while(m--)
        {
            cin >> x >> y;
            bad[{x,y}]=bad[{y,x}]=1;
        }
        for(auto [x,v] : cnt)values[v].emplace_back(x);
        ans=0;
        for(i=1;i<=n;i++)reverse(values[i].begin(),values[i].end());
        for(i=1;i<n;i++)
        {
            for(int x : values[i])
            {
                for(j=1;j<=i;j++)
                {
                    for(int y : values[j])
                    {
                        if(x == y  ||  bad.find({x,y}) != bad.end())continue;
                        ans=max(ans, 1ll*(i+j)*(x+y));
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
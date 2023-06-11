#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool mark[M];
vector<int>adj[M];
int ans[M],cnt[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            cnt[i]=mark[i]=0;
        }
        while(m--)
        {
            cin >> x >> y;
            ++cnt[x], ++cnt[y];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        set<pair<int,int>>st;
        for(i=1;i<=n;i++)st.insert({cnt[i],i});
        for(i=n;i;i--)
        {
            auto [v,id]=*(st.begin());
            st.erase(st.begin());
            for(int it : adj[id])
            {
                if(mark[it])continue;
                st.erase({cnt[it],it});
                st.insert({--cnt[it],it});
            }
            ans[id]=i, mark[id]=1;
        }
        for(i=1;i<=n;i++)
        {
            cnt[i]=0;
            for(int it : adj[i])cnt[i] += (ans[it] < ans[i]);
        }
        sort(cnt+1,cnt+n+1);
        cout << cnt[n]-cnt[1] << '\n';
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
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
const int M=4e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int sz[M];
vector<int>adj[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
            sz[i]=0;
            adj[i].clear();
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            ++sz[x], ++sz[y];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        if(n == 1)
        {
            cout << "0\n";
            continue;
        }
        ans=n;
        deque<int>dq;
        for(i=1;i<=n;i++)
        {
            if(sz[i] == 1)dq.emplace_back(i);
        }
        while(k--)
        {
            i=(int)dq.size();
            ans -= i;
            while(i--)
            {
                x=dq.front(),dq.pop_front();
                for(int y : adj[x])
                {
                    --sz[x], --sz[y];
                    if(sz[y] == 1)dq.emplace_back(y);
                }
            }
            if(dq.empty())break;
        }
        cout << ans << '\n';
    }
    return 0;
}
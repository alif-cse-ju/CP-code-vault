#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int l[M],r[M];
vector<int>adj[M];
long long dp[M][2];
long long DP(int x,int p,bool bit)
    long long &ans=dp[x][bit];
    if(ans > -1)return ans;
    ans=0;
    for(int y : adj[x])
    {
        if(y ^ p)
        {
            if(bit)ans+=max(abs(r[x]-l[y])+DP(y,x,0),abs(r[x]-r[y])+DP(y,x,1));
            else ans+=max(abs(l[x]-l[y])+DP(y,x,0),abs(l[x]-r[y])+DP(y,x,1));
        }
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> l[i] >> r[i];
            adj[i].clear();
            dp[i][0]=dp[i][1]=-1;
        }
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        cout << max(DP(1,0,0),DP(1,0,1)) << '\n';
    }
    return 0;
}
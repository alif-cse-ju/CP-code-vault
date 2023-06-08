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
const int sz = 1e3+5;
priority_queue<pair<int,int>>pq;
int ans[sz][20*sz],b[sz],c[sz],dp[sz];
void PreCal()
    int i,y;
    for(i=2;i<sz;i++)dp[i]=sz;
    pq.emplace(0,1);
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop();
        v *= (-1);
        for(i=1;i<=x;i++)
        {
            y=x+(x/i);
            if(y >= sz)continue;
            if(dp[y] > v+1)dp[y]=v+1, pq.emplace(-dp[y],y);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n,sum,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> b[i];
        for(i=1;i<=n;i++)cin >> c[i];
        for(i=1, sum=0;i<=n;i++)b[i]=dp[b[i]], sum+=b[i];
        k=min(k, sum);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {
                if(b[i] > j)ans[i][j]=ans[i-1][j];
                else ans[i][j]=max(ans[i-1][j], ans[i-1][j-b[i]]+c[i]);
            }
        }
        cout << ans[n][k] << '\n';
    }
    return 0;
}
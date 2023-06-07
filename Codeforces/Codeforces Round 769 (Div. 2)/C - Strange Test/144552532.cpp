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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int dp[N];
bool visited[N];
priority_queue<pair<int,int>>pq;
void Dijkstra()
    int i,y;
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop();
        if(visited[x])continue;
        visited[x]=1, v *= (-1);
        for(i=20;i>=0;i--)
        {
            if((x >> i) & 1)
            {
                y=x ^ (1 << i);
                if(dp[y] > v)
                {
                    dp[y]=v;
                    pq.emplace(-dp[y],y);
                }
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        for(i=0;i<b;i++)dp[i]=N+N, visited[i]=0;
        for(i=b;i<=b+b-a;i++)dp[i]=i-b+1, visited[i]=0, pq.emplace(-dp[i],i);
        Dijkstra(), dp[b]=0;
        for(i=b-1;i>=a;i--)dp[i]=min(dp[i], dp[i+1]+1);
        cout << dp[a] << '\n';
    }
    return 0;
}
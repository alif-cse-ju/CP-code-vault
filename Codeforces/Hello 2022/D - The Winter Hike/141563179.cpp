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
const int M=500+5;
const int N=2e6+5;
const int mod=1e9+7;
ll cost[M][M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t;
    ll ans,must,sum1,sum2,tmp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=2*n;i++)
        {
            for(j=1;j<=2*n;j++)cin >> cost[i][j];
        }
        must=0;
        for(i=n+1;i<=2*n;i++)
        {
            for(j=n+1;j<=2*n;j++)must += cost[i][j], cost[i][j]=0;
        }
        ans=LLONG_MAX;
         ans=min(ans, cost[1][2*n]);
        ans=min(ans, cost[1][n+1]);
         ans=min(ans, cost[2*n][1]);
        ans=min(ans, cost[2*n][n]);
         ans=min(ans, cost[n][n+1]);
        ans=min(ans, cost[n][n+n]);
         ans=min(ans, cost[n+1][1]);
        ans=min(ans, cost[n+1][n]);
         tmp=0;
        for(i=1;i<=n;i++)tmp += cost[i][n+1];
        ans=min(ans,tmp);
        tmp=0;
        for(i=1;i<=n;i++)tmp += cost[i][2*n];
        ans=min(ans,tmp);
         tmp=0;
        for(i=1;i<=n;i++)tmp += cost[n+1][i];
        ans=min(ans,tmp);
        tmp=0;
        for(i=1;i<=n;i++)tmp += cost[2*n][i];
        ans=min(ans,tmp);
         vector<ll>dq;
        sum1=sum2=0;
        for(i=1;i<=n;i++)dq.emplace_back(cost[i][2*n]), sum2 += cost[i][n+n];
        tmp=LLONG_MAX;
        reverse(dq.begin(),dq.end());
        for(i=1;i<=n;i++)
        {
            sum1+=cost[n+i][1], sum2-=dq.back(), dq.pop_back();
            tmp=min(tmp,sum1+sum2);
        }
        ans=min(ans,tmp);
         dq.clear();
        sum1=sum2=0;
        for(i=1;i<=n;i++)dq.emplace_back(cost[i][n+1]), sum2 += cost[i][n+1];
        tmp=LLONG_MAX;
        reverse(dq.begin(),dq.end());
        for(i=1;i<=n;i++)
        {
            sum1+=cost[n+i][n], sum2-=dq.back(), dq.pop_back();
            tmp=min(tmp,sum1+sum2);
        }
        ans=min(ans,tmp);
         dq.clear();
        sum1=sum2=0;
        for(i=1;i<=n;i++)dq.emplace_back(cost[n+1][i]), sum2 += cost[n+1][i];
        tmp=LLONG_MAX;
        reverse(dq.begin(),dq.end());
        for(i=1;i<=n;i++)
        {
            sum1+=cost[n][n+i], sum2-=dq.back(), dq.pop_back();
            tmp=min(tmp,sum1+sum2);
        }
        ans=min(ans,tmp);
         dq.clear();
        sum1=sum2=0;
        for(i=1;i<=n;i++)dq.emplace_back(cost[2*n][i]), sum2 += cost[2*n][i];
        tmp=LLONG_MAX;
        reverse(dq.begin(),dq.end());
        for(i=1;i<=n;i++)
        {
            sum1+=cost[1][n+i], sum2-=dq.back(), dq.pop_back();
            tmp=min(tmp,sum1+sum2);
        }
        ans=min(ans,tmp);
         cout << ans+must << '\n';
    }
    return 0;
}
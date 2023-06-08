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
ll a[102],dp[102][3][3],n;
ll DP(int id,int _1,int _2)
    if(id > n)return 0;
    ll &ans=dp[id][_1][_2];
    if(ans > -1)return ans;
    int i,j,mx=-1,v;
    for(i=0;i<=_1;i++)
    {
        for(j=0;j<=_2;j++)
        {
            v=i+2*j;
            if(v%3 == a[id]%3  &&  v <= a[id])mx=max(mx,v);
        }
    }
    if(mx == -1)ans=1e12;
    else ans=max((a[id]-mx)/3, DP(id+1,_1,_2));
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int cnt,i,j,k,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1,cnt=0;i<=n;i++)
        {
            cin >> a[i], cnt+=((a[i]%3) == 0);
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)dp[i][j][k]=-1;
            }
        }
        sort(a+1,a+n+1);
        if(cnt == n)cout << a[n]/3 << '\n';
        else
        {
            ans=LLONG_MAX;
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)ans=min(ans,i+j+DP(1,i,j));
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
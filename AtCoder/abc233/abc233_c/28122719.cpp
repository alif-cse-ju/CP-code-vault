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

int n,sz[65];
vector<ll>v[65];
map<ll,ll>dp[65];

ll DP(int i,ll val)
{
    if(i > n)return (val == 1);
    if(dp[i].find(val) != dp[i].end())return dp[i][val];
    ll ans=0;
    for(int j=0;j<sz[i];j++)
    {
        if(v[i][j] > val)break;
        if(val%v[i][j])continue;
        ans += DP(i+1,val/v[i][j]);
    }
    return dp[i][val]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    int i,j,l;
    cin >> n >> x;
    if(n >= 60)
    {
        for(i=1;i<=n;i++)
        {
            cin >> l;
            while(l--)cin >> y;
        }
        cout << "0";
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            cin >> sz[i];
            for(j=1;j<=sz[i];j++)cin >> y, v[i].emplace_back(y);
            sort(v[i].begin(),v[i].end());
        }
        cout << DP(1,x);
    }
    return 0;
}

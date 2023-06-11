#pragma GCC optimize("Ofast")
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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
int dp[M],n;
vector<int>pos[M][26];
void Update(int i)
{
    while(i)++dp[i], i-=(i & -i);
}
int Query(int i)
{
    int ans=0;
    while(i <= n)ans += dp[i], i+=(i & -i);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m;cin >> n >> m;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<26;j++)pos[i][j].clear();
        }
        for(int i=1;i<=n;i++)
        {
            cin >> s+1;
            for(int j=1;j<=m;j++)pos[j][s[j]-'a'].emplace_back(i);
        }
        ll ans=0;
        bool ok=1;
        for(int i=1;i<=m/2  &&  ok;i++)
        {
            int l=i, r=m-i+1;
            vector<pair<int,int>>v;
            for(int j=0;j<26  &&  ok;j++)
            {
                ok &= ((int)pos[l][j].size() == (int)pos[r][j].size());
                if(!ok)continue;
                for(int k=0;k<min((int)pos[l][j].size() , (int)pos[r][j].size());k++)v.emplace_back(pos[l][j][k
            }
            if(!ok)continue;
            for(int j=1;j<=n;j++)dp[j]=0;
            sort(v.begin(), v.end());
            for(auto [x,y] : v) ans += Query(y), Update(y);
        }
        if(!ok)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}
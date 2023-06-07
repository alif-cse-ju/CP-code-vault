#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e3+5;
const int N=2e6+5;
const int mod=1e9+7;
vector<int>border[2*M];
int dp[2*M][2*M],l[M],r[M];
int DP(int l,int r)
    if(l > r)return 0;
    int &ans=dp[l][r];
    if(ans != -1)return ans;
    ans=0;
    for(int it : border[l])
    {
        if(it < r)ans=max(ans,DP(l,it) + DP(it+1,r));
    }
    ans=max(ans,DP(l+1,r));
    for(int it : border[l])ans += (it == r);
    return ans;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        for(i=1;i<=n;i++)cin >> l[i] >> r[i], st.insert(l[i]), st.insert(r[i]);
        map<int,int>mp;
        cnt=0;
        for(int it : st)mp[it]=++cnt;
        for(i=1;i<=cnt;i++)
        {
            border[i].clear();
            for(j=i;j<=cnt;j++)dp[i][j]=-1;
        }
        for(i=1;i<=n;i++)
        {
            l[i]=mp[l[i]], r[i]=mp[r[i]];
            border[l[i]].emplace_back(r[i]);
        }
        cout << DP(1,cnt) << '\n';
    }
    return 0;
}
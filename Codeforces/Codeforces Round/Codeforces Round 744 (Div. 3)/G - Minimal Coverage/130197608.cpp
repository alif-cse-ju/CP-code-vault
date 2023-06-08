#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e4+5;
const int N=2e3+5;
const int mod=1e9+7;
int n,a[M],dp[M][N];
int DP(int i,int pos)
    if(pos >= N)return 1e9;
    if(i > n)return 0;
    int &ans=dp[i][pos];
    if(ans > -1)return ans;
    ans=max(pos+a[i],DP(i+1,pos+a[i]));
    if(pos-a[i] >= 0)ans=min(ans,max(pos,DP(i+1,pos-a[i])));
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=INT_MAX;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            memset(dp[i],-1,sizeof(dp[i]));
        }
        for(i=0;i<=1000;i++)ans=min(ans,DP(1,i));
        cout << ans << '\n';
    }
    return 0;
}
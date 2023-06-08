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
const int M=1e5+5;
const int N=2e3+5;
const int mod=1e9+7;
int k,n,a[N],dp[N][N];
int DP(int idx,int shaua,int dlt)
    if(dlt < 0  ||  idx > n)return 0;
    int &ans=dp[idx][dlt];
    if(ans > -1)return ans;
    ans=DP(idx+1,shaua+1,dlt-1);
    ans=max(ans,DP(idx+1,shaua,dlt)+(a[idx] == idx-shaua));
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,l,m,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        l=0,r=n,ans=-1;
        while(l <= r)
        {
            m=(l+r) >> 1;
            for(i=1;i<=n;i++)
            {
                for(j=0;j<=m;j++)dp[i][j]=-1;
            }
            if(DP(1,0,m) >= k)ans=m,r=m-1;
            else l=m+1;
        }
        cout << ans << '\n';
    }
    return 0;
}
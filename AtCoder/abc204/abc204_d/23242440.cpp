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

int n,a[102],dp[N];

int DP(int idx,int val)
{
    if(val < 0)return 0;
    if(!val)return 1;
    if(idx > n)return 0;
    int &ans=dp[val];
    if(ans >= 0)return ans;
    ans=DP(idx+1,val-a[idx]) | DP(idx+1,val);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,sum=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=sum;i++)
    {
        if(DP(1,i)  &&  sum-i <= i)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}

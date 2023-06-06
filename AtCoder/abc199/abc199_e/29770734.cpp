#pragma GCC optimize("Ofast")

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
const int mod=998244353;

const int sz = (1 << 18)+5;

ll dp[sz];
int mx[18][18],n;

ll DP(int idx, int mask)
{
    if(idx == n)return 1;
    ll &ans=dp[mask];
    if(ans > -1)return ans;
    ans=0;
    int i,j,newMask;
    for(i=0;i<n;i++)
    {
        if((mask >> i) & 1)continue;
        mask |= (1 << i);
        for(j=0;j<n;j++)
        {
            newMask=mask & ((1 << (j+1))-1);
            if(__builtin_popcount(newMask) > mx[idx][j])break;
        }
        if(j == n)ans += DP(idx+1, mask);
        mask ^= (1 << i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,x,y,z;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)mx[i][j]=25;
    }
    while(m--)
    {
        cin >> x >> y >> z;
        --x, --y, mx[x][y]=min(mx[x][y], z);
    }
    memset(dp,-1,sizeof(dp));
    cout << DP(0, 0);
    return 0;
}
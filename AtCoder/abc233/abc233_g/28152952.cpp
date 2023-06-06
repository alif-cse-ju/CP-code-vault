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

char s[52][52];
int dp[52][52][52][52];

int DP(int lx,int ly,int rx,int ry)
{
    if(lx > rx  ||  ly > ry)return 0;
    int &ans=dp[lx][ly][rx][ry];
    if(ans > -1)return ans;
    ans=max(rx-lx, ry-ly) + 1;
    int i,j;
    for(i=lx;i<=rx;i++)
    {
        for(j=ly;j<=ry;j++)
        {
            if(s[i][j] == '#')break;
        }
        if(j > ry)ans=min(ans, DP(lx,ly,i-1,ry) + DP(i+1,ly,rx,ry));
    }

    for(i=ly;i<=ry;i++)
    {
        for(j=lx;j<=rx;j++)
        {
            if(s[j][i] == '#')break;
        }
        if(j > rx)ans=min(ans, DP(lx,ly,rx,i-1) + DP(lx,i+1,rx,ry));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> s[i]+1;
    memset(dp,-1,sizeof(dp));
    cout << DP(1,1,n,n);
    return 0;
}

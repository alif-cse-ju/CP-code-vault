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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int a[M];
char s[M];
ll dp[M][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l;cin >> l >> s+1;
    for(int i=1;i<=l;i++)cin >> a[i];
    string ss="hard";
    for(int j=1;j<5;j++)dp[0][j]=1e15;
    for(int i=1;i<=l;i++)
    {
        for(int j=0;j<5;j++)dp[i][j]=1e15;
        for(int j=0;j<4;j++)
        {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+a[i]);
            if(s[i] == ss[j])dp[i][j+1]=min(dp[i][j+1], dp[i-1][j]);
            else dp[i][j]=min(dp[i][j], dp[i-1][j]);
        }
    }
    cout << min({dp[l][0], dp[l][1], dp[l][2], dp[l][3]});
    return 0;
}
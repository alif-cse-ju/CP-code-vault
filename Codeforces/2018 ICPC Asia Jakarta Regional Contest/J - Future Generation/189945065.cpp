#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 const int mx = (1<<15)+5;
 string s[16];
int l[16],la,lb;
pair<string,int>dp[2][mx];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++) cin >> s[i], l[i]=(int)s[i].size();
    la=(1 << l[1]), dp[1][0].second=INT_MIN;
    for(int j=1;j<la;j++)
    {
        for(int k=0;k<l[1];k++)
        {
            if((j >> k) & 1)dp[1][j].first += s[1][k];
        }
        dp[1][j].second=__builtin_popcount(j);
    }
    sort(dp[1]+1,dp[1]+la);
    for(int i=1;i<la;i++)dp[1][i].second=max(dp[1][i-1].second,dp[1][i].second);
    for(int i=2;i<=n;i++)
    {
        int b=i%2;
        lb=(1 << l[i]), dp[b][0].second=INT_MIN;
        for(int j=1;j<lb;j++)
        {
            dp[b][j].first="";
            for(int k=0;k<l[i];k++)
            {
                if((j >> k) & 1)dp[b][j].first += s[i][k];
            }
            dp[b][j].second=__builtin_popcount(j);
        }
        sort(dp[b]+1,dp[b]+lb);
        int L=0;
        for(int j=1;j<lb;j++)
        {
            while(L+1 < la  &&  dp[1-b][L+1].first < dp[b][j].first)++L;
            dp[b][j].second=max(dp[b][j-1].second, dp[1-b][L].second+dp[b][j].second);
        }
        la=lb;
    }
    if(dp[n%2][la-1].second < 0)dp[n%2][la-1].second=-1;
    cout << dp[n%2][la-1].second;
    return 0;
}
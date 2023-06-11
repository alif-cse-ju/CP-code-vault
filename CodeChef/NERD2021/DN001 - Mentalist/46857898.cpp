#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e3+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],dp[M][M][2];
int DP(int l,int r,bool bit)
{
    if(l == r)return (bit ? a[l] : 0);
    int &ans=dp[l][r][bit];
    if(ans > -1)return ans;
    if(bit)ans=max(a[l]+DP(l+1,r,0),a[r]+DP(l,r-1,0));
    else ans=min(DP(l+1,r,1),DP(l,r-1,1));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l;
    string s;
    cin >> s;
    l=(int)s.size();
    for(i=0;i<l;i++)a[i+1]=26-(s[i]-'a');
    memset(dp,-1,sizeof(dp));
    cout << DP(1,l,1);
    return 0;
}
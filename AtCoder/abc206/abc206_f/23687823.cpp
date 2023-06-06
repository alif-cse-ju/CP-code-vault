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

const int M=1e2+5;
const int N=2e5+5;
const int mod=1e9+7;

int n,L[M],R[M],dp[M][M];

int DP(int l,int r)
{
    if(l >= r)return 0;
    int &ans=dp[l][r];
    if(ans > -1)return ans;
    bool mark[200]={0};
    for(int i=1;i<=n;i++)
    {
        if(L[i] >= l  &&  R[i] <= r)mark[DP(l,L[i]) ^ DP(R[i],r)]=1;
    }
    for(int i=0; ;i++)
    {
        if(!mark[i])return ans=i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> L[i] >> R[i];
        memset(dp,-1,sizeof(dp));
        if(DP(1,100))cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
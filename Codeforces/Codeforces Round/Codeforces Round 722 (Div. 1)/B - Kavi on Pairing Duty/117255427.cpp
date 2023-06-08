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
const int M=1e6+5;
const int N=2e5+5;
const int mod=998244353;
long long cnt[M],dp[M];
void PreCal()
    int i,j;
    for(i=1;i<M;i++)
    {
        for(j=i;j<M;j+=i)++cnt[j];
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    PreCal();
    dp[1]=1;
    cin >> n;
    for(i=2;i<=n;i++)dp[i]=(dp[i-1]*2+cnt[i])%mod;
    cout << (dp[n]-dp[n-1]+mod)%mod;
    return 0;
}
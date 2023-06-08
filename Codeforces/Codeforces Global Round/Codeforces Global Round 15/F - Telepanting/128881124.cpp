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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int n;
bool active[M];
ll X[M],Y[M],dp[M],sum[M];
void Update(int i,int v)
    while(i <= n)
    {
        sum[i] += v;
        i += (i & -i);
    }
ll Query(int i)
    ll ans=0;
    while(i)
    {
        ans += sum[i];
        i -= (i & -i);
    }
    return ans%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,x;
    ll ans,tmp;
    ordered_set<int>ost;
    cin >> n;
    for(i=1;i<=n;i++)cin >> X[i] >> Y[i] >> x,active[i]=x;
    for(i=1;i<=n;i++)
    {
        tmp=X[i]-Y[i];
        tmp+=Query(i-1) - Query(ost.order_of_key(Y[i]));
        tmp %= mod;
        if(tmp < 0)tmp+=mod;
        dp[i]=tmp;
        Update(i,tmp);
        ost.insert(X[i]);
    }
    ans=X[n]+1;
    for(i=1;i<=n;i++)
    {
        if(active[i])ans+=dp[i];
    }
    cout << ans%mod;
    return 0;
}
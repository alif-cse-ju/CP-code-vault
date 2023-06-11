#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M],divs[N],dp[M],pos[N];
void PreCal()
{
    for(int i=2;i<N;i+=2)divs[i]=2;
    for(int i=3;i<N;i+=2)
    {
        if(!divs[i])
        {
            for(int j=i;j<N;j+=i)
            {
                if(!divs[j])divs[j]=i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=0;i<n;i++)cin >> a[i];
        bool ok=0;
        for(int i=1;i<n  &&  !ok;i++)ok |= (__gcd(a[i], a[i-1]) == 1);
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        for(int i=1;i<N;i++)pos[i]=n;
        dp[n]=n;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=dp[i+1];
            int x=a[i];
            while(x > 1)dp[i]=min(dp[i], pos[divs[x]]), x/=divs[x];
            x=a[i];
            while(x > 1)pos[divs[x]]=i, x/=divs[x];
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans, dp[i]-i);
        cout << ans << '\n';
    }
    return 0;
}
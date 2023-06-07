#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll h[M],preE[M],preO[M],sufE[M],sufO[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> h[i];
        if(n & 1)
        {
            ll ans=0;
            for(int i=2;i<n;i+=2)ans += max(0ll, max(h[i-1], h[i+1])-h[i]+1);
            cout << ans << '\n';
        }
        else
        {
            for(int i=0;i<=n+5;i++)preE[i]=preO[i]=sufE[i]=sufO[i]=0;
            for(int i=2;i<n;i+=2)preE[i]=sufE[i]=max(0ll, max(h[i-1], h[i+1])-h[i]+1);
            for(int i=3;i<n;i+=2)preO[i]=sufO[i]=max(0ll, max(h[i-1], h[i+1])-h[i]+1);
             for(int i=4;i<n;i+=2)preE[i]+=preE[i-2];
            for(int i=5;i<n;i+=2)preO[i]+=preO[i-2];
             for(int i=n-4;i;i-=2)sufE[i]+=sufE[i+2];
            for(int i=n-3;i>1;i-=2)sufO[i]+=sufO[i+2];
             ll ans=min(sufE[2], preO[n-1]);
            for(int i=2;i+3<n;i+=2)
            {
                if(i & 1)ans=min(ans, preO[i]+sufE[i+3]);
                else ans=min(ans, preE[i]+sufO[i+3]);
            }
             cout << ans << '\n';
        }
    }
    return 0;
}
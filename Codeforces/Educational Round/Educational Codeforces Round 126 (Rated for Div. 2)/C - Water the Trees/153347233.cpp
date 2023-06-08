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
const int mod=998244353;
ll h[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll sum=0;
        for(int i=1;i<=n;i++)cin >> h[i], sum+=h[i];
        sort(h+1,h+n+1);
        int par0=0, par1;
        for(int i=1;i<n;i++)par0 += ((h[n]-h[i]) & 1ll);
        par1=n-par0;
        ll l=0,r=1e15;
        while(l <= r)
        {
            ll mid=(l+r) >> 1ll;
            ll cnt1=(mid+1) >> 1ll, cnt2=(mid >> 1ll) << 1ll;
            if(h[n]*n <= sum+cnt1+cnt2  &&  par0 <= cnt1)r=mid-1;
            else if((h[n]+1)*n <= sum+cnt1+cnt2  &&  par1 <= cnt1)r=mid-1;
            else l=mid+1;
        }
        cout << r+1 << '\n';
    }
    return 0;
}
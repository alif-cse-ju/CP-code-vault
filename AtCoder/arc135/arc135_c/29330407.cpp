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

int cnt[32],a[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    ll ans=0,tmp;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i], ans+=a[i];
        for(j=0;j<30;j++)
        {
            if((a[i] >> j) & 1)++cnt[j];
        }
    }
    for(i=1;i<=n;i++)
    {
        tmp=0;
        for(j=0;j<30;j++)
        {
            if((a[i] >> j) & 1)tmp += 1ll*(n-cnt[j])*(1ll << j);
            else tmp += 1ll*cnt[j]*(1ll << j);
        }
        ans=max(ans, tmp);
    }
    cout << ans;
    return 0;
}
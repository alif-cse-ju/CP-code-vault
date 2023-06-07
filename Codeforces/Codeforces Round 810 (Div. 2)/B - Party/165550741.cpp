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

int a[M],x[M],y[M],in[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=1;i<=n;i++)cin >> a[i], in[i]=0;
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            cin >> x[i] >> y[i];
            ++in[x[i]], ++in[y[i]], ++cnt;
        }
        int ans=0;
        if(cnt & 1)
        {
            ans=INT_MAX;
            for(int i=1;i<=n;i++)
            {
                if(in[i] & 1)ans=min(ans, a[i]);
            }
            for(int i=1;i<=m;i++)
            {
                if((in[x[i]]+in[y[i]]-1) & 1)ans=min(ans, a[x[i]]+a[y[i]]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

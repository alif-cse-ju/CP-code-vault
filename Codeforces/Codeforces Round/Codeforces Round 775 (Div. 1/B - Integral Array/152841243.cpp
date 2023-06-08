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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
ll a[N],cnt[N],tot[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int c,i,j,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(i=1;i<=c;i++)cnt[i]=0;
        for(i=1;i<=n;i++)cin >> a[i], ++cnt[a[i]];
        for(i=1;i<=c;i++)tot[i] = tot[i-1]+cnt[i];
        for(i=ok=1;i<=c  &&  ok;i++)
        {
            if(!cnt[i])continue;
            for(j=1;i*j<=c;j++)
            {
                if(tot[min(c, i*(j+1)-1)] - tot[i*j-1])
                {
                    if(!cnt[j])
                    {
                        ok=0;
                        break;
                    }
                }
            }
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
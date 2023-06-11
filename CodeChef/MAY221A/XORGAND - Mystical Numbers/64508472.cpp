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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int cnt[M][32],cnt0[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int n;cin >> n;
            for(int i=1;i<=n;i++)
            {
                    int x;cin >> x;
                    cnt0[i]=cnt0[i-1];
                    for(int j=30;j>=0;j--)cnt[i][j]=cnt[i-1][j];
                    if(!x)
                    {
                            ++cnt0[i];
                            continue;
                    }
                    for(int j=30;j>=0;j--)
                    {
                            if((x >> j) & 1)
                            {
                                    ++cnt[i][j];
                                    break;
                            }
                    }
            }
            int q;cin >> q;
            while(q--)
            {
                    int l,r,x;cin >> l >> r >> x;
                    int msb=-1;
                    for(int i=30;i>=0;i--)
                    {
                            if((x >> i) & 1)
                            {
                                    msb=i;
                                    break;
                            }
                    }
                    int ans=0;
                    for(int i=msb+1;i<31;i++)ans += cnt[r][i]-cnt[l-1][i];
                    for(int i=msb-1;i>=0;i--)ans += cnt[r][i]-cnt[l-1][i];
                    if(x)ans += cnt0[r]-cnt0[l-1];
                    cout << ans << '\n';
            }
    }
    return 0;
}
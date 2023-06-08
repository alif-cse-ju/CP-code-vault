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
bool present[M];
int a[M],n,sum[M];
void Update(int i)
    while(i <= n)++sum[i], i+=(i & -i);
int Query(int i)
    int ans=0;
    while(i)ans+=sum[i], i-=(i & -i);
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int s;cin >> n >> s;
        for(int i=1;i<=n;i++)cin >> a[i], present[i]=sum[i]=0;
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            int x;cin >> x;
            if(x == -1)Update(a[i]);
            else
            {
                if(a[i] > x+s)ans=0;
                else present[x]=1;
            }
        }
        if(!ans)cout << "0\n";
        else
        {
            ans=1;
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(!present[i])
                {
                    int pos=Query(min(i+s, n));
                    pos -= cnt;
                    if(pos <= 0)
                    {
                        ans=0;
                        break;
                    }
                    ans=(ans*pos) % mod, ++cnt;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
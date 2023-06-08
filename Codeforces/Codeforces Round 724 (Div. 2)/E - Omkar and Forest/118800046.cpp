#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e3+5;
const int mod=1e9+7;
char grid[N];
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,cnt,i,j,m,n,t;
    cin >> t;
    while(t--)
    {
        cnt=0;
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cin >> grid+1;
            for(j=1;j<=m;j++)cnt+=(grid[j] == '#');
        }
        ans=BigMod(2,cnt);
        if(cnt == m*n)ans=(ans+mod-1)%mod;
        cout << ans << '\n';
    }
    return 0;
}
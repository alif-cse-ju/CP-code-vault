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
const int mod=1e9+7;
int n;
ll ans;
bool mark[16];
void DP(int id,int mask)
    if(__builtin_popcount(mask) == n)
    {
        ++ans;
        return;
    }
    int i,x;
    for(i=0;i<n;i++)
    {
        if((mask >> i) & 1)continue;
        x=i-id;
        if(x < 0)x += n;
        if(!mark[x])
        {
            mark[x]=1;
            DP(id+1,mask | (1 << i));
            mark[x]=0;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(!(n & 1))
    {
        cout << "0";
        return 0;
    }
    if(n == 15)ans=36362925;
    else DP(0,0);
    for(int i=2;i<=n;i++)ans=(ans*i)%mod;
    cout << ans;
    return 0;
}
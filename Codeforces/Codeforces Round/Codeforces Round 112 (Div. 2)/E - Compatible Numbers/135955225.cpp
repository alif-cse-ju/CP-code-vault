#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
bool pos[(1 << 22)];
int a[N],dp[(1 << 22)];
void PreCal(int n)
    int i,j,mask;
    n=(1 << n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<22;j++)
        {
            if((i >> j) & 1)
            {
                mask=i ^ (1 << j);
                if(pos[mask])pos[i]=1, dp[i]=dp[mask];
            }
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i], pos[a[i]]=1, dp[a[i]]=a[i];
    PreCal(22);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<22;j++)a[i] ^= (1 << j);
        if(!pos[a[i]])cout << "-1 ";
        else cout << dp[a[i]] << ' ';
    }
    return 0;
}
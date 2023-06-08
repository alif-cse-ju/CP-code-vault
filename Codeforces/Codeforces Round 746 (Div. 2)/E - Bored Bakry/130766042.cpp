#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+9;
int a[N],cur[N],last[M+N],val[N],xr[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,m=0,n,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=19;i>=0;i--)
    {
        m |= (1 << i);
        for(j=1;j<=n;j++)cur[j]=(a[j] & m);
        for(j=1;j<=n;j++)xr[j]=(cur[j] ^ xr[j-1]);
        memset(last,-1,sizeof(last));
        val[0]=last[0]=0;
        for(j=k=1;j<=n;j++)
        {
            if((cur[j] >> i) & 1)
            {
                if(last[xr[j]] > -1)ans=max(ans,j-last[xr[j]]);
                else last[xr[j]]=j,val[k++]=xr[j];
            }
            else
            {
                while(k--)last[val[k]]=-1;
                val[0]=xr[j],last[xr[j]]=j,k=1;
            }
        }
    }
    cout << ans;
    return 0;
}
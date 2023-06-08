#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M];
long long ans,cnt[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,n,r,q;
    cin >> n >> q >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    if(n > 1)cnt[1]=a[2]-1;
    cnt[n]=k-a[n-1];
    for(i=2;i<n;i++)cnt[i]=(a[i+1]-a[i-1]-1)+cnt[i-1];
    cnt[n]+=cnt[n-1];
    while(q--)
    {
        cin >> l >> r;
        if(l == r)cout << k-1 << '\n';
        else
        {
            ans=cnt[r-1]-cnt[l];
            ans+=k+a[l+1]-a[r-1]-2-r+l;
            cout << ans << '\n';
        }
    }
    return 0;
}
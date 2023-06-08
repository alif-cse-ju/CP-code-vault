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
const int N=2e5+5;
const int mod=1e9+7;
int a[M],b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,k,l,m,n,r,scrA,scrB,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(i=1;i<=n;i++)a[i]+=a[i-1],b[i]+=b[i-1];
        ans=l=0,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            k=(m+n)-(m+n)/4;
            scrA=100*min(m,k)+a[n]-a[n-max(0,k-m)],scrB=b[n]-b[max(0,n-k)];
            if(scrA >= scrB)ans=m,r=m-1;
            else l=m+1;
        }
        cout << ans << '\n';
    }
    return 0;
}
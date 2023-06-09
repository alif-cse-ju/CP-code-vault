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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int k,n,a[M],sum[M];
bool Check(const int& sz)
    for(int i=sz;i<=n;i++)
    {
        if(sum[i]-sum[i-sz] >= n-(sum[i]-sum[i-sz])+k)return 1;
    }
    return 0;
int Y(const int& sz)
    for(int i=sz;i<=n;i++)
    {
        if(sum[i]-sum[i-sz] >= n-(sum[i]-sum[i-sz])+k)return i;
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,m,r,csum,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)sum[i]=0;
        for(i=1;i<=n;i++)cin >> a[i], ++sum[a[i]];
        for(i=2;i<=n;i++)sum[i] += sum[i-1];
        l=0, r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(Check(m))r=m-1;
            else l=m+1;
        }
        y=Y(++r), x=y-r+1, --k;
        cout << x << ' ' << y << '\n';
        for(i=1;i<=n  &&  k;i++,k--)
        {
            csum=0;
            for(j=i;j<=n;j++)
            {
                if(a[j] >= x  &&  a[j] <= y)++csum;
                else --csum;
                if(csum == 1)break;
            }
            cout << i << ' ' << j << '\n';
            i=j;
        }
        cout << i << ' ' << n << '\n';
    }
    return 0;
}
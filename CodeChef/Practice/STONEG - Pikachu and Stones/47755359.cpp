#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long a[M],fr[M],rv[M],dpF[M],dpR[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    long long ans,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        dpF[1]=dpR[n]=0;
        fr[1]=a[1],rv[n]=a[n];
        for(i=2;i<n;i++)
        {
            if(a[i] <= fr[i-1])
            {
                fr[i]=fr[i-1]+1;
                dpF[i]=fr[i]-a[i];
            }
            else fr[i]=a[i],dpF[i]=0;
            dpF[i]+=dpF[i-1];
        }
        for(i=n-1;i > 1;i--)
        {
            if(a[i] <= rv[i+1])
            {
                rv[i]=rv[i+1]+1;
                dpR[i]=rv[i]-a[i];
            }
            else rv[i]=a[i],dpR[i]=0;
            dpR[i]+=dpR[i+1];
        }
        ans=LLONG_MAX;
        for(i=2;i<n;i++)
        {
            x=max(fr[i-1],rv[i+1])+1;
            ans=min(ans,max(0ll,x-a[i])+dpF[i-1]+dpR[i+1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
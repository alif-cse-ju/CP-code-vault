#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
int a[M],b[M],l[M],r[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=m;i++)cin >> b[i];
        for(i=1;i<=n;i++)
        {
            l[i]=l[i-1];
            if(a[i] == 1)l[i]=i;
        }
        r[n+1]=1e9;
        for(i=n;i;i--)
        {
            r[i]=r[i+1];
            if(a[i] == 2)r[i]=i;
        }
        for(i=1;i<=m;i++)
        {
            ans=INT_MAX;
            if(b[i] == 1)ans=0;
            if(l[b[i]] > 0)ans=min(ans,b[i]-l[b[i]]);
            if(r[b[i]] <= n)ans=min(ans,r[b[i]]-b[i]);
            if(ans == INT_MAX)ans=-1;
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
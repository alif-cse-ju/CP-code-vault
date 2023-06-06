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

const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int a[M],b[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,l1,l2,n,ans=0,last;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=m;i++)cin >> b[i];
    last=a[1],l1=n+1,l2=0;
    for(i=1;i<=m;i++)
    {
        if(last == b[i])continue;
        last=1-last;
        for(j=2;j<=n;j++)
        {
            if(a[j] == last)
            {
                l1=j;
                break;
            }
        }
        if(l1 > n)
        {
            cout << "-1";
            return 0;
        }
        for(j=n;j;j--)
        {
            if(a[j] == last)
            {
                l2=j;
                break;
            }
        }
        break;
    }
    if(i <= m)ans+=min(l1-1,n-l2+1);
    for(i=i+1;i<=m;i++)
    {
        if(b[i] != last)last=1-last,++ans;
    }
    cout << ans+m;
    return 0;
}

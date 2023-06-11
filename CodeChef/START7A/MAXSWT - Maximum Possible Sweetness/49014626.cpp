#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int p[M];
pair<int,int>a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,i,l,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        ordered_set<int>ost;
        for(i=1;i<=n;i++)cin >> a[i].first,ost.insert(a[i].first);
        for(i=1;i<=n;i++)cin >> a[i].second;
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)p[i]=a[i].second;
        for(i=2;i<=n;i++)p[i]=max(p[i-1],p[i]);
        ans=0;
        for(i=n;i;i--)
        {
            if(a[i].first > d)continue;
            l=ost.order_of_key(d-a[i].first+1);
            ans=max(ans,a[i].second+p[min(l,i-1)]);
        }
        cout << ans << '\n';
    }
    return 0;
}
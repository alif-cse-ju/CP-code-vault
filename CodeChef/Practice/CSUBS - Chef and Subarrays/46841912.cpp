#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n,t,ans,cnt,mx;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> a[i];
        map<int,int>mark;
        for(i=1,ans=0;i<=k;i++)
        {
            mark.clear();
            for(j=i,cnt=0;j<=n;j+=k)++cnt,++mark[a[j]];
            mx=0;
            for(auto it : mark)mx=max(mx,it.second);
            ans+=cnt-mx;
        }
        cout << ans << '\n';
    }
    return 0;
}
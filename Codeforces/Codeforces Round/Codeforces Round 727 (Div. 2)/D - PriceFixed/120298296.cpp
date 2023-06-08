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
pair<ll,ll>a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    ll x,y,ans=0,cnt=0,mn;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y;
        a[i]={y,x};
    }
    sort(a+1,a+n+1);
    for(i=1,j=n;i <= j;i++)
    {
        while(i <= j  &&  cnt < a[i].first)
        {
            mn=min(a[i].first-cnt,a[j].second);
            ans+=2*mn,cnt+=mn,a[j].second-=mn;
            if(!a[j].second)--j;
        }
        if(i <= j)ans+=a[i].second,cnt+=a[i].second;
    }
    cout << ans;
    return 0;
}
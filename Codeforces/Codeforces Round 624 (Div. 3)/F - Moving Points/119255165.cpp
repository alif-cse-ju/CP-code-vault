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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int m;
ll sum[N];
pair<ll,ll>a[N];
void Update(int i,ll val)
    while(i <= m)
    {
        sum[i]+=val;
        i+=i & -i;
    }
ll Query(int i)
    ll ans=0;
    while(i)
    {
        ans+=sum[i];
        i-=i & -i;
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    long long ans=0;
    set<int>st;
    map<int,int>mp;
    ordered_set<int>ost;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i].first;
    for(i=1;i<=n;i++)cin >> a[i].second,st.insert(a[i].second);
    for(int v : st)mp[v]=++m;
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        ans+=ost.order_of_key(a[i].second+1)*a[i].first-Query(mp[a[i].second]);
        Update(mp[a[i].second],a[i].first);
        ost.insert(a[i].second);
    }
    cout << ans;
    return 0;
}
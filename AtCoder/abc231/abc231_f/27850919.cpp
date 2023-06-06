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

pair<int,int>c[M];
int a[M],b[M],cnt[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,n;
    cin >> n;
    set<int>sta,stb;
    map<int,int>mpa,mpb;
    for(i=1;i<=n;i++)cin >> a[i], sta.insert(a[i]);
    for(i=1;i<=n;i++)cin >> b[i], stb.insert(b[i]);
    i=0; for(int it : sta)mpa[it]=++i;
    i=0; for(int it : stb)mpb[it]=++i;
    for(i=1;i<=n;i++)a[i]=mpa[a[i]];
    for(i=1;i<=n;i++)b[i]=mpb[b[i]];
    for(i=1;i<=n;i++)c[i]={a[i],b[i]};
    ans=1ll*n*n;
    for(i=1;i<=n;i++)++cnt[a[i]], ans-=(i-cnt[a[i]]);
    for(i=1;i<=n;i++)++cnt[i]=0;
    for(i=1;i<=n;i++)++cnt[b[i]], ans-=(i-cnt[b[i]]);
    sort(c+1,c+n+1);
    ordered_set<int>ost;
    for(i=1;i<=n;i++)ost.insert(c[i].second), ans += i-ost.order_of_key(c[i].second+1);
    cout << ans;
    return 0;
}

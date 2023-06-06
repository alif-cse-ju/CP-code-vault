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
const int N=3e5+5;
const int mod=1e9+7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>mp;
    int i,k,n,ans,cnt=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=k;i++)
    {
        ++mp[a[i]];
        if(mp[a[i]] == 1)++cnt;
    }
    ans=cnt;
    for(i=k+1;i<=n;i++)
    {
        ++mp[a[i]];
        if(mp[a[i]] == 1)++cnt;
        --mp[a[i-k]];
        if(!mp[a[i-k]])--cnt;
        ans=max(ans,cnt);
    }
    cout << ans;
    return 0;
}

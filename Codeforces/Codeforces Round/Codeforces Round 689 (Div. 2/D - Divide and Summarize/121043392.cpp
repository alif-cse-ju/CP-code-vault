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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
ll a[M];
map<ll,bool>mp;
void PreCal(int l,int r)
    ll sum=0;
    int mid=(a[l]+a[r])/2,pos=r+1;
    for(int i=l;i<=r;i++)
    {
        sum+=a[i];
        if(a[i] <= mid)pos=i;
    }
    mp[sum]=1;
    if(pos < r)
    {
        PreCal(l,pos);
        PreCal(pos+1,r);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,q,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        mp.clear();
        PreCal(1,n);
        while(q--)
        {
            cin >> x;
            cout << (mp.find(x) == mp.end() ? "No\n" : "Yes\n");
        }
    }
    return 0;
}
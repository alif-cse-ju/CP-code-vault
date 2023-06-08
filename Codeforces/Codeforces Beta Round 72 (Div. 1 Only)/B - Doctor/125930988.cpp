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
const int N=1e6+5;
const int mod=1e9+7;
int n;
ll a[M];
ll Check(const ll val)
    ll sum=0;
    for(int i=1;i<=n;i++)sum+=min(a[i],val);
    return sum;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    ll k,l,m,r,mx=0,sum=0;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i],sum+=a[i];
    if(sum < k)cout << "-1";
    else
    {
        l=0,r=k;
        while(l <= r)
        {
            m=(l+r) >> 1ll;
            if(Check(m) <= k)mx=m,l=m+1;
            else r=m-1;
        }
        k-=Check(mx);
        for(i=1;i<=n;i++)a[i]=max(0ll,a[i]-mx);
        deque<int>dq;
        for(i=1;i<=n;i++)
        {
            if(a[i])dq.emplace_back(i);
        }
        while(k--)
        {
            m=dq.front();
            dq.pop_front();
            if(--a[m])dq.emplace_back(m);
        }
        while(!dq.empty())cout << dq.front() << ' ',dq.pop_front();
    }
    return 0;
}
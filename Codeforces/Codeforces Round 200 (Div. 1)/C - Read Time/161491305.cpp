#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll h[M],p[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> h[i];
    for(int i=1;i<=m;i++)cin >> p[i];

    ll l=0,r=2000000000000;
    while(l <= r)
    {
        ll md=(l+r) >> 1ll;
        deque<ll>dq;
        for(int i=1;i<=m;i++)dq.emplace_back(p[i]);
        for(int i=1;i<=n  &&  !dq.empty();i++)
        {
            if(h[i]-md > dq.front())break;
            ll mn=h[i],mx=h[i];
            if(dq.front() <= h[i])
            {
                mn=dq.front();
                while(!dq.empty()  &&  dq.front() <= h[i])dq.pop_front();
            }
            while(!dq.empty()  &&  min(h[i]+dq.front()-2ll*mn, 2ll*dq.front()-mn-h[i]) <= md)dq.pop_front();
        }
        if(dq.empty())r=md-1;
        else l=md+1;
    }
    cout << r+1;
    return 0;
}

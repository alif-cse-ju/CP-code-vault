#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    deque<pair<int,int>>dq;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int c,x;
            cin >> x >> c;
            dq.emplace_back(c,x);
        }
        else
        {
            int c;
            cin >> c;
            ll ans=0;
            while(c)
            {
                auto [x,y]=dq.front(); dq.pop_front();
                int z=min(x,c);
                ans+=1ll*z*y, c-=z, x-=z;
                if(x)dq.emplace_front(x,y);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
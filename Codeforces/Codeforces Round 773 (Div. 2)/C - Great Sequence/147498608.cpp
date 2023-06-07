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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,x,y;
    int ans,i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans=0;
        multiset<ll>mst;
        while(n--)cin >> x, mst.insert(x);
        while(!mst.empty())
        {
            x=*(mst.begin()), mst.erase(mst.begin());
            y=k*x;
            if(mst.find(y) == mst.end())++ans;
            else mst.erase(mst.find(y));
        }
        cout << ans << '\n';
    }
    return 0;
}
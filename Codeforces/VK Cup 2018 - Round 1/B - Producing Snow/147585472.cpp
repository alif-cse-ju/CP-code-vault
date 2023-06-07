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
struct VeniceSet
    multiset<ll>mst;
    ll waterLevel=0;
    void Add(ll v)
    {
        mst.insert(v+waterLevel);
    }
    void Remove(ll v)
    {
        mst.erase(mst.find(v+waterLevel));
    }
    void UpdateAll(ll v)
    {
        waterLevel += v;
    }
    ll GetMin()
    {
        return *mst.begin()-waterLevel;
    }
    int size()
    {
        return (int)mst.size();
    }
};
 ll t[M],v[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    ll ans,x;
    cin >> n;
    for(i=0;i<n;i++)cin >> v[i];
    for(i=0;i<n;i++)cin >> t[i];
    VeniceSet vSet;
    for(i=0;i<n;i++)
    {
        vSet.Add(v[i]);
        vSet.UpdateAll(t[i]);
        ans=t[i]*vSet.size();
        while(vSet.size()  &&  vSet.GetMin() < 0)
        {
            x=vSet.GetMin();
            ans += x, vSet.Remove(x);
        }
        cout << ans << ' ';
    }
    return 0;
}
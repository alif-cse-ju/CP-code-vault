#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
const int M=4e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 ll segTree[4*M],lazy[4*M];
 void Update(int nodeNum,int start,int end,int l,int r,ll value)
{
    if(lazy[nodeNum] != -1)
    {
        segTree[nodeNum]=lazy[nodeNum];
        if(start != end) lazy[nodeNum*2]=lazy[nodeNum*2 + 1]=lazy[nodeNum];
        lazy[nodeNum]=-1;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        segTree[nodeNum]=value;
        if(start != end) lazy[nodeNum*2]=lazy[nodeNum*2 + 1]=value;
        return;
    }
    int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);
    segTree[nodeNum]=(segTree[nodeNum*2] | segTree[nodeNum*2 + 1]);
}
 ll Query(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(lazy[nodeNum] != -1)
    {
        segTree[nodeNum]=lazy[nodeNum];
        if(start != end) lazy[nodeNum*2]=lazy[nodeNum*2 + 1]=lazy[nodeNum];
        lazy[nodeNum]=-1;
    }
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int mid=(start+end)/2;
    ll ans1=Query(nodeNum*2,start,mid,l,r);
    ll ans2=Query(nodeNum*2 + 1,mid+1,end,l,r);
    return (ans1 | ans2);
}
 vector<int>adj[M];
int clr[M],in[M],out[M],tim;
 void DFS(int x,int p)
{
    in[x]=++tim;
    for(int &y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
    out[x]=tim;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> clr[i];
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y), adj[y].emplace_back(x);
    }
    DFS(1,0);
    for(int i=1;i<=n;i++)Update(1,1,n,in[i],in[i],(1ll << clr[i]));
    while(q--)
    {
        int op;cin >> op;
        if(op == 1)
        {
            int x,c;cin >> x >> c;
            Update(1,1,n,in[x],out[x],(1ll << c));
        }
        else
        {
            int x;cin >> x;
            ll ans=Query(1,1,n,in[x],out[x]);
            cout << __builtin_popcountll(ans) << '\n';
        }
    }
    return 0;
}
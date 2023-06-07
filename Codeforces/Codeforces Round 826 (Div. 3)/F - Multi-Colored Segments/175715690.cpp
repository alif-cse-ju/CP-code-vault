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

tuple<int,int,int,int>segs[M];
int ans[M],segTree[4*M],newID[M];
vector<tuple<int,int,int>>segments[M];

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        segTree[nodeNum]=get<1>(segs[l]);
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    segTree[nodeNum]=max(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}

void Update(int nodeNum,int l,int r,int id,int v)
{
    if(l == r)
    {
        segTree[nodeNum]=v;
        return;
    }
    int m=(l+r) >> 1;
    if(id <= m)Update(2*nodeNum,l,m,id,v);
    else Update(2*nodeNum+1,m+1,r,id,v);
    segTree[nodeNum]=max(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}

int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l > r)return -mod;
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return max(Query(2*nodeNum,start,m,l,r), Query(2*nodeNum+1,m+1,end,l,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        ordered_set<int>ost;
        for(int i=1;i<=n;i++)ans[i]=INT_MAX, segments[i].clear();
        for(int i=1;i<=n;i++)
        {
            int c,l,r;cin >> l >> r >> c;
            segs[i]=make_tuple(l,r,c,i), ost.insert(l);
        }
        sort(segs+1,segs+n+1);
        for(int i=1;i<=n;i++)
        {
            auto [l,r,c,id]=segs[i];
            newID[id]=i, segments[c].emplace_back(make_tuple(l,r,id));
        }
        Build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            for(auto [l,r,id] : segments[i])
            {
                Update(1,1,n,newID[id],-mod);
                ost.erase(ost.find_by_order(ost.order_of_key(l)));
            }
            for(auto [l,r,id] : segments[i])
            {
                int v=Query(1,1,n,1,newID[id]);
                ans[id]=min(ans[id], max(0, l-v));
                int small=ost.order_of_key(l);
                if(small < (int)ost.size())ans[id]=min(ans[id], max(0, *ost.find_by_order(small)-r));
            }
            for(auto [l,r,id] : segments[i])Update(1,1,n,newID[id],r), ost.insert(l);
        }
        for(int i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}

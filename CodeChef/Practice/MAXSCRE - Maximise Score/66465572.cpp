#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
pair<int,int>segTree[4*M];
void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        segTree[nodeNum]={0,l};
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    segTree[nodeNum]=min(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
void Update(int nodeNum,int start,int end,int i,int val)
{
    if(start == end)
    {
        segTree[nodeNum]={val,i};
        return;
    }
    int m=(start+end) >> 1;
    if(i <= m)Update(2*nodeNum,start,m,i,val);
    else Update(2*nodeNum+1,m+1,end,i,val);
    segTree[nodeNum]=min(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
pair<int,int>Query(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    else if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return min(Query(2*nodeNum,start,m,l,r), Query(2*nodeNum+1,m+1,end,l,r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<tuple<int,int,int,int>>vec;
        for(int i=0;i<n;i++)
        {
            int l,r,v;cin >> l >> r >> v;
            vec.emplace_back(make_tuple(r-l,l,r,v));
        }
        sort(vec.begin(),vec.end());
        Build(1,1,n);
        ll ans=0;
        for(auto [d,l,r,v] : vec)
        {
            auto [vv,i]=Query(1,1,n,l,r);
            if(vv >= v)continue;
            ans += v-vv, Update(1,1,n,i,v);
        }
        cout << ans << '\n';
    }
    return 0;
}
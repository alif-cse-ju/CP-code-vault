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
const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;
tuple<int,int,int>a[M];
int segTree[4*M],X[M],Y[M],Z[M];
void Update(int nodeNum,int l,int r,int id,int val)
    if(l == r)
    {
        segTree[nodeNum]=max(segTree[nodeNum], val);
        return;
    }
    int m=(l+r) >> 1;
    if(id <= m)Update(2*nodeNum,l,m,id,val);
    else Update(2*nodeNum+1,m+1,r,id,val);
    segTree[nodeNum]=max(segTree[2*nodeNum], segTree[2*nodeNum+1]);
 int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l > r)return 0;
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    else if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return max(Query(2*nodeNum,start,m,l,m), Query(2*nodeNum+1,m+1,end,m+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    set<int>st;
    for(int i=1;i<=n;i++)cin >> X[i];
    for(int i=1;i<=n;i++)cin >> Y[i], st.insert(Y[i]);
    for(int i=1;i<=n;i++)cin >> Z[i];
    map<int,int>mp;
    int cnt=0;
    for(int it : st)mp[it]=++cnt;
    for(int i=1;i<=n;i++)Y[i]=mp[Y[i]];
    for(int i=1;i<=n;i++)a[i]=make_tuple(X[i],Y[i],Z[i]);
    sort(a+1,a+n+1);
    int ans=0;
    vector<tuple<int,int,int>>v;
    for(int i=n;i;i--)
    {
        auto [x,y,z]=a[i];
        int zz=Query(1,1,cnt,y+1,cnt);
        ans += (zz > z);
        v.emplace_back(a[i]);
        auto [x1,y1,z1]=a[i-1];
        if(x != x1)
        {
            while(!v.empty())
            {
                auto [x2,y2,z2]=v.back();
                v.pop_back();
                Update(1,1,cnt,y2,z2);
            }
        }
    }
    cout << ans;
    return 0;
}
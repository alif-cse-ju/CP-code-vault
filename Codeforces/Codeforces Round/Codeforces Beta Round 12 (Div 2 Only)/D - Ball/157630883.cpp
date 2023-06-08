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
struct Data {
    int x,y,z;
[M];
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
}
 int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l > r)return 0;
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    else if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return max(Query(2*nodeNum,start,m,l,m), Query(2*nodeNum+1,m+1,end,m+1,r));
}
 bool compare(Data &a,Data &b)
{
    if(a.x == b.x)
    {
        if(a.y == b.y)return a.z <= b.z;
        return a.y <= b.y;
    }
    return a.x <= b.x;
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
    for(int i=1;i<=n;i++)a[i].x=X[i], a[i].y=Y[i], a[i].z=Z[i];
    sort(a+1,a+n+1,compare);
    int ans=0;
    vector<Data>v;
    for(int i=n;i;i--)
    {
        int zz=Query(1,1,cnt,a[i].y+1,cnt);
        ans += (zz > a[i].z);
        v.emplace_back(a[i]);
        if(a[i].x != a[i-1].x)
        {
            while(!v.empty())
            {
                Data d=v.back();
                v.pop_back();
                Update(1,1,cnt,d.y,d.z);
            }
        }
    }
    cout << ans;
    return 0;
}
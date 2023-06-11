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
const int M=2e5+5;
const int N=5e6+5;
const int mod=998244353;
vector<int>adj[4*M];
int a[M],b[M],c[M],d[M],dist[4*M],segTree[16*M];
int Get(int i,int j)
{
    if(b[i] > b[j])return i;
    return j;
}
void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        if(adj[l].empty())segTree[nodeNum]=0;
        else segTree[nodeNum]=adj[l].back();
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    segTree[nodeNum]=Get(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
int Query(int nodeNum,int start,int end,int l,int r)
{
    if(start >= l  &&  end <= r)return segTree[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return Get(Query(2*nodeNum,start,m,l,r), Query(2*nodeNum+1,m+1,end,l,r));
}
void Update(int nodeNum,int l,int r,int pos)
{
    if(l == r)
    {
        if(!adj[l].empty())adj[l].pop_back();
        if(adj[l].empty())segTree[nodeNum]=0;
        else segTree[nodeNum]=adj[l].back();
        return;
    }
    int m=(l+r) >> 1;
    if(pos <= m)Update(2*nodeNum,l,m,pos);
    else Update(2*nodeNum+1,m+1,r,pos);
    segTree[nodeNum]=Get(segTree[2*nodeNum], segTree[2*nodeNum+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n,x,y;cin >> n >> m >> x >> y;
        set<int>st;
        st.insert(x), st.insert(y);
        for(int i=1;i<=m;i++)
        {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
            st.insert(a[i]), st.insert(b[i]), st.insert(c[i]), st.insert(d[i]);
        }
        map<int,int>mp; n=0;
        for(int it : st)mp[it]=++n;
        st.clear(), x=mp[x], y=mp[y];
        for(int i=1;i<=n;i++)adj[i].clear(), dist[i]=n+n, st.insert(i);
        for(int i=1;i<=m;i++)
        {
            a[i]=mp[a[i]], b[i]=mp[b[i]], c[i]=mp[c[i]], d[i]=mp[d[i]];
            adj[a[i]].emplace_back(i);
        }
        for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end(),[&](int i,int j) { return b[i] < b[j]; });
        Build(1,1,n);
        queue<int>q;
        q.emplace(x), dist[x]=0, st.erase(x);
        while(!q.empty())
        {
            int x=q.front(); q.pop();
            int i=Query(1,1,n,1,x);
            while(b[i] >= x)
            {
                Update(1,1,n,a[i]);
                int l=c[i], r=d[i];
                while(true)
                {
                    auto it=st.lower_bound(l);
                    if(it == st.end()  ||  *it > r)break;
                    dist[*it]=dist[x]+1, q.emplace(*it), st.erase(*it);
                }
                i=Query(1,1,n,1,x);
            }
        }
        if(dist[y] > n)dist[y]=-1;
        cout << dist[y] << '\n';
    }
    return 0;
}
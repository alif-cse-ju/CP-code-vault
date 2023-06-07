#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int mod=998244353;
const ll mx=1e18;
ll points[M];
bool flip[4*M];
int _tree[4*M],lazy[4*M];
void Propagate(int nodeNum,int l,int r)
    if(lazy[nodeNum] != -1)
    {
        _tree[nodeNum]=(r-l+1)*lazy[nodeNum];
        if(l != r)
        {
            flip[nodeNum*2]=flip[nodeNum*2 + 1]=0;
            lazy[nodeNum*2]=lazy[nodeNum*2 + 1]=lazy[nodeNum];
        }
        lazy[nodeNum]=-1;
    }
    if(flip[nodeNum])
    {
        _tree[nodeNum]=(r-l+1)-_tree[nodeNum];
        if(l != r)flip[nodeNum*2] ^= 1, flip[nodeNum*2 + 1] ^= 1;
        flip[nodeNum]=0;
    }
}
 void Update(int nodeNum,int start,int end,int l,int r,int val)
{
    Propagate(nodeNum,start,end);
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        if(val != 2)lazy[nodeNum]=val, flip[nodeNum]=0;
        else flip[nodeNum] ^= 1;
        Propagate(nodeNum,start,end);
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,val);
    Update(nodeNum*2 + 1,mid+1,end,l,r,val);
     _tree[nodeNum]=_tree[nodeNum*2] + _tree[nodeNum*2 + 1];
}
 int Query(int nodeNum,int l,int r)
{
    if(l == r)return l;
    Propagate(nodeNum,l,r);
    int mid=(l+r) >> 1;
    Propagate(2*nodeNum,l,mid);
    Propagate(2*nodeNum+1,mid+1,r);
    if(_tree[2*nodeNum])return Query(2*nodeNum,l,mid);
    return Query(2*nodeNum+1,mid+1,r);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    ll l,m,r,v;
    set<ll>distinctPoints;
    map<ll,int>mappedPoints;
    vector<tuple<int,ll,ll>>queries;
    cin >> n;
    distinctPoints.insert(1);
    distinctPoints.insert(mx+1);
    while(n--)cin >> t >> l >> r, queries.emplace_back(make_tuple(t,l,r)), distinctPoints.insert(l), distinctPoints.insert(r);
    n=points[0]=0;
    for(ll it : distinctPoints)
    {
        if(it-1 != points[n])points[n+1]=points[n]+1, mappedPoints[points[n+1]]=++n;
        points[++n]=it, mappedPoints[it]=n;
    }
    memset(lazy,-1,sizeof(lazy));
    Update(1,1,n,1,n,1);
    for(auto [t,l,r] : queries)
    {
        Update(1,1,n,mappedPoints[l],mappedPoints[r],t-1);
        cout << points[Query(1,1,n)] << '\n';
    }
    return 0;
}
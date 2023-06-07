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

const int M=1e5+5;
const int N=2e6+5;
const int mod=95542721;

int lazy[4*M];
ll a[M],_tree[4*M][48],tmp[50];

long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        _tree[nodeNum][0]=a[l];
        for(int i=1;i<48;i++)_tree[nodeNum][i]=BigMod(_tree[nodeNum][i-1], 3);
        return;
    }
    int m=(l+r) >> 1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    for(int i=0;i<48;i++)
    {
        _tree[nodeNum][i]=_tree[2*nodeNum][i] + _tree[2*nodeNum+1][i];
        if(_tree[nodeNum][i] >= mod)_tree[nodeNum][i] -= mod;
    }
}

void Update(int nodeNum,int start,int end,int l,int r)
{
    if(lazy[nodeNum])
    {
        for(int i=0;i<48;i++)
        {
            int j=i+lazy[nodeNum];
            if(j >= 48)j -= 48;
            tmp[i]=_tree[nodeNum][j];
        }
        for(int i=0;i<48;i++)_tree[nodeNum][i]=tmp[i];
        if(start != end)
        {
            lazy[nodeNum*2] += lazy[nodeNum];
            if(lazy[2*nodeNum] >= 48)lazy[2*nodeNum] -= 48;

            lazy[nodeNum*2 + 1] += lazy[nodeNum];
            if(lazy[2*nodeNum+1] >= 48)lazy[2*nodeNum+1] -= 48;
        }
        lazy[nodeNum]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        for(int i=0;i<48;i++)
        {
            int j=i+1;
            if(j >= 48)j -= 48;
            tmp[i]=_tree[nodeNum][j];
        }
        for(int i=0;i<48;i++)_tree[nodeNum][i]=tmp[i];
        if(start != end)
        {
            ++lazy[nodeNum*2], ++lazy[nodeNum*2 + 1];
            if(lazy[2*nodeNum] >= 48)lazy[2*nodeNum] -= 48;
            if(lazy[2*nodeNum+1] >= 48)lazy[2*nodeNum+1] -= 48;
        }
        return;
    }

    int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r);
    Update(nodeNum*2 + 1,mid+1,end,l,r);

    for(int i=0;i<48;i++)
    {
        _tree[nodeNum][i]=_tree[2*nodeNum][i] + _tree[2*nodeNum+1][i];
        if(_tree[nodeNum][i] >= mod)_tree[nodeNum][i] -= mod;
    }
}

ll Query(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(lazy[nodeNum] != 0)
    {
        for(int i=0;i<48;i++)
        {
            int j=i+lazy[nodeNum];
            if(j >= 48)j -= 48;
            tmp[i]=_tree[nodeNum][j];
        }
        for(int i=0;i<48;i++)_tree[nodeNum][i]=tmp[i];
        if(start != end)
        {
            lazy[nodeNum*2] += lazy[nodeNum];
            if(lazy[2*nodeNum] >= 48)lazy[2*nodeNum] -= 48;

            lazy[nodeNum*2 + 1] += lazy[nodeNum];
            if(lazy[2*nodeNum+1] >= 48)lazy[2*nodeNum+1] -= 48;
        }
        lazy[nodeNum]=0;
    }
    if(start >= l  &&  end <= r)return _tree[nodeNum][0];
    int mid=(start+end)/2;
    return (Query(nodeNum*2,start,mid,l,r) + Query(nodeNum*2 + 1,mid+1,end,l,r)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i], a[i]%=mod;
    Build(1,1,n);
    int q;cin >> q;
    while(q--)
    {
        int l,r,t;cin >> t >> l >> r;
        if(t == 1)cout << Query(1,1,n,l,r) << '\n';
        else Update(1,1,n,l,r);
    }
    return 0;
}
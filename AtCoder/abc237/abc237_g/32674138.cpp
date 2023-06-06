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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int lazy[4*M][2],segTree[4*M][2];

void Update(int nodeNum,int start,int end,int l,int r,int value,int id)
{
    if(lazy[nodeNum][id] != -1)
    {
        segTree[nodeNum][id]=(end-start+1)*lazy[nodeNum][id];
        if(start != end)lazy[nodeNum*2][id]=lazy[nodeNum*2 + 1][id]=lazy[nodeNum][id];
        lazy[nodeNum][id]=-1;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        segTree[nodeNum][id]=(end-start+1)*value;
        if(start != end)lazy[nodeNum*2][id]=lazy[nodeNum*2 + 1][id]=value;
        return;
    }

    int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value,id);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value,id);

    segTree[nodeNum][id]=segTree[nodeNum*2][id] + segTree[nodeNum*2 + 1][id];
}

int Query(int nodeNum,int start,int end,int l,int r,int id)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(lazy[nodeNum][id] != -1)
    {
        segTree[nodeNum][id]=(end-start+1)*lazy[nodeNum][id];
        if(start != end)lazy[nodeNum*2][id]=lazy[nodeNum*2 + 1][id]=lazy[nodeNum][id];
        lazy[nodeNum][id]=-1;
    }
    if(start >= l  &&  end <= r)return segTree[nodeNum][id];

    int mid=(start+end)/2;
    return (Query(nodeNum*2,start,mid,l,r,id) + Query(nodeNum*2 + 1,mid+1,end,l,r,id));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,X;cin >> n >> q >> X;
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        if(x < X)Update(1,1,n,i,i,0,0);
        else Update(1,1,n,i,i,1,0);

        if(x <= X)Update(1,1,n,i,i,0,1);
        else Update(1,1,n,i,i,1,1);
    }
    while(q--)
    {
        int l,ones,r,t;cin >> t >> l >> r;
        if(t == 1)
        {
            ones=Query(1,1,n,l,r,0);
            Update(1,1,n,l,r-ones,0,0);
            Update(1,1,n,r-ones+1,r,1,0);

            ones=Query(1,1,n,l,r,1);
            Update(1,1,n,l,r-ones,0,1);
            Update(1,1,n,r-ones+1,r,1,1);
        }
        else
        {
            ones=Query(1,1,n,l,r,0);
            Update(1,1,n,l,l+ones-1,1,0);
            Update(1,1,n,l+ones,r,0,0);

            ones=Query(1,1,n,l,r,1);
            Update(1,1,n,l,l+ones-1,1,1);
            Update(1,1,n,l+ones,r,0,1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(Query(1,1,n,i,i,0) != Query(1,1,n,i,i,1))
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
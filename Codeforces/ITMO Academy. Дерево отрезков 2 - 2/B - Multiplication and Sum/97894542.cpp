#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
const long long mod=1e9+7;
 long long tree[4*N],lazy[4*N];
 void Build(int nodeNum,int l,int r)
{
    lazy[nodeNum]=1;
    if(l == r)
    {
        tree[nodeNum]=1;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    tree[nodeNum]=tree[2*nodeNum] + tree[2*nodeNum+1];
}
 void Update(int nodeNum,int start,int end,int l,int r,long long value)
{
    if(lazy[nodeNum] != 1)
    {
        tree[nodeNum]=(tree[nodeNum]*lazy[nodeNum])%mod;
        if(start != end)
        {
            lazy[nodeNum*2]=(lazy[nodeNum*2]*lazy[nodeNum])%mod;
            lazy[nodeNum*2 + 1]=(lazy[nodeNum*2 + 1]*lazy[nodeNum])%mod;
        }
        lazy[nodeNum]=1;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        tree[nodeNum]=(tree[nodeNum]*value)%mod;
        if(start != end)
        {
            lazy[nodeNum*2]=(lazy[nodeNum*2]*value)%mod;
            lazy[nodeNum*2 + 1]=(lazy[nodeNum*2 + 1]*value)%mod;
        }
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);
     tree[nodeNum]=(tree[nodeNum*2] + tree[nodeNum*2 + 1])%mod;
}
 long long Query(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(lazy[nodeNum] != 1)
    {
        tree[nodeNum]=(tree[nodeNum]*lazy[nodeNum])%mod;
        if(start != end)
        {
            lazy[nodeNum*2]=(lazy[nodeNum*2]*lazy[nodeNum])%mod;
            lazy[nodeNum*2 + 1]=(lazy[nodeNum*2 + 1]*lazy[nodeNum])%mod;
        }
        lazy[nodeNum]=1;
    }
    if(start >= l  &&  end <= r)return tree[nodeNum]%mod;
     int mid=(start+end)/2;
    long long ans1=Query(nodeNum*2,start,mid,l,r);
    long long ans2=Query(nodeNum*2 + 1,mid+1,end,l,r);
     return (ans1+ans2)%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,m,n,r,x,op;
    cin >> n >> m;
    Build(1,1,n);
    while(m--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r >> x;
            Update(1,1,n,++l,r,x);
        }
        else
        {
            cin >> l >> r;
            cout << Query(1,1,n,++l,r) << '\n';
        }
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int N=3e5+5;
const int mod=1e9+7;

int a[N],node[4*N];

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }

    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=(node[2*nodeNum] ^ node[2*nodeNum+1]);
}

void Update(int nodeNum,int start,int end,int pos,int x)
{
    if(start == end)
    {
        node[nodeNum] ^= x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=(node[2*nodeNum] ^ node[2*nodeNum+1]);
}

int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return (Query(nodeNum*2,start,mid,l,mid) ^ Query(nodeNum*2+1,mid+1,end,mid+1,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,q,r,op;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    while(q--)
    {
        cin >> op >> l >> r;
        if(op == 1)Update(1,1,n,l,r);
        else cout << Query(1,1,n,l,r) << '\n';
    }
    return 0;
}
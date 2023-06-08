#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
 int cnt0[4*N],cnt1[4*N],lazy[4*N];
 void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        cnt0[nodeNum]=1;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    cnt0[nodeNum]=cnt0[2*nodeNum] + cnt0[2*nodeNum+1];
}
 void Update(int nodeNum,int start,int end,int l,int r)
{
    if(lazy[nodeNum] != 0)
    {
        swap(cnt0[nodeNum],cnt1[nodeNum]);
        if(start != end)
        {
            lazy[nodeNum*2]^=1;
            lazy[nodeNum*2 + 1]^=1;
        }
        lazy[nodeNum]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        swap(cnt0[nodeNum],cnt1[nodeNum]);
        if(start != end)
        {
            lazy[nodeNum*2]^=1;
            lazy[nodeNum*2 + 1]^=1;
        }
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r);
    Update(nodeNum*2 + 1,mid+1,end,l,r);
     cnt0[nodeNum]=cnt0[nodeNum*2] + cnt0[nodeNum*2 + 1];
    cnt1[nodeNum]=cnt1[nodeNum*2] + cnt1[nodeNum*2 + 1];
}
 void Propagate(int nodeNum,int l,int r)
{
    if(!lazy[nodeNum])return;
    swap(cnt0[nodeNum],cnt1[nodeNum]);
    if(l != r)
    {
        lazy[nodeNum*2]^=1;
        lazy[nodeNum*2 + 1]^=1;
    }
    lazy[nodeNum]=0;
}
 int Query(int nodeNum,int start,int end,int idx)
{
    if(start == end)return start;
    int mid=(start+end)/2;
    Propagate(2*nodeNum,start,mid);
    Propagate(2*nodeNum+1,mid+1,end);
    if(cnt1[2*nodeNum] >= idx)return Query(nodeNum*2,start,mid,idx);
    return Query(nodeNum*2 + 1,mid+1,end,idx-cnt1[2*nodeNum]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,m,n,r,op;
    cin >> n >> m;
    Build(1,1,n);
    while(m--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r;
            Update(1,1,n,++l,r);
        }
        else
        {
            cin >> l;
            cout << Query(1,1,n,++l)-1 << '\n';
        }
    }
    return 0;
}
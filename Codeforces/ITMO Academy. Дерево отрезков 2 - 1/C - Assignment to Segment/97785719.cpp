#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
 int tree[4*N],lazy[4*N];
 void Update(int nodeNum,int start,int end,int l,int r,int value)
{
    if(lazy[nodeNum] != -1)
    {
        tree[nodeNum]=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]=lazy[nodeNum];
            lazy[nodeNum*2 + 1]=lazy[nodeNum];
        }
        lazy[nodeNum]=-1;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        tree[nodeNum]=value;
        if(start != end)
        {
            lazy[nodeNum*2]=value;
            lazy[nodeNum*2 + 1]=value;
        }
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);
}
 int Query(int nodeNum,int start,int end,int idx)
{
    if(lazy[nodeNum] != -1)
    {
        tree[nodeNum]=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]=lazy[nodeNum];
            lazy[nodeNum*2 + 1]=lazy[nodeNum];
        }
        lazy[nodeNum]=-1;
    }
    if(start == end)return tree[nodeNum];
    int mid=(start+end)/2;
    if(idx <= mid)return Query(nodeNum*2,start,mid,idx);
    return Query(nodeNum*2 + 1,mid+1,end,idx);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,m,n,r,x,op;
    cin >> n >> m;
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
            cin >> l;
            cout << Query(1,1,n,++l) << '\n';
        }
    }
    return 0;
}
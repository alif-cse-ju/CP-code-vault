#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long tree[4*N],lazy[4*N];
void Update(int nodeNum,int start,int end,int l,int r,int value)
    if(lazy[nodeNum] != 0)
    {
        tree[nodeNum]+=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]+=lazy[nodeNum];
            lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        tree[nodeNum]+=value;
        if(start != end)
        {
            lazy[nodeNum*2]+=value;
            lazy[nodeNum*2 + 1]+=value;
        }
        return;
    }
    int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);
    tree[nodeNum]=min(tree[2*nodeNum],tree[2*nodeNum+1]);
long long Query(int nodeNum,int start,int end,int l,int r)
{
    if(lazy[nodeNum] != 0)
    {
        tree[nodeNum]+=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]+=lazy[nodeNum];
            lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
    if(start >= l  &&  end <= r)return tree[nodeNum];
    int mid=(start+end)/2;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    else if(l > mid)return Query(nodeNum*2+1,mid+1,end,l,r);
    return min(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2 + 1,mid+1,end,mid+1,r));
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
            cin >> l >> r;
            cout << Query(1,1,n,++l,r) << '\n';
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+5;
int ans[M];
ll _tree[4*M],lazy[4*M];
void Propagate(int nodeNum,int start,int end)
    if(lazy[nodeNum] != 0)
    {
        _tree[nodeNum]+=lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]+=lazy[nodeNum];
            lazy[nodeNum*2 + 1]+=lazy[nodeNum];
        }
        lazy[nodeNum]=0;
    }
void Update(int nodeNum,int start,int end,int l,int r,ll value)
    Propagate(nodeNum,start,end);
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        _tree[nodeNum]+=value;
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
    _tree[nodeNum]=min(_tree[2*nodeNum],_tree[2*nodeNum+1]);
}
 int Query(int nodeNum,int start,int end)
{
    Propagate(nodeNum,start,end);
    if(start == end)return start;
    int mid=(start+end)/2;
    Propagate(2*nodeNum,start,mid);
    Propagate(2*nodeNum+1,mid+1,end);
    if(_tree[nodeNum] != _tree[2*nodeNum+1])return Query(nodeNum*2,start,mid);
    return Query(nodeNum*2+1,mid+1,end);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    int i,l,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        Update(1,1,n,i,i,x);
    }
    for(i=1;i<=n;i++)
    {
        l=Query(1,1,n);
        ans[l]=i;
        if(l < n)Update(1,1,n,l+1,n,-i);
        Update(1,1,n,l,l,1e18);
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}
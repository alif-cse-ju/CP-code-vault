#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct Data
    int l,r,evenSum,oddSum;
int a[N+2];
Data node[4*N+2];
Data Merge(Data &x,Data &y)
    Data ans;
    ans.l=x.l,ans.r=y.r;
    ans.oddSum=x.oddSum+y.oddSum;
    ans.evenSum=x.evenSum+y.evenSum;
    return ans;
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum].l=node[nodeNum].r=l;
        if(l & 1)node[nodeNum].oddSum=a[l];
        else node[nodeNum].evenSum=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=Merge(node[2*nodeNum],node[2*nodeNum+1]);
void Update(int nodeNum,int start,int end,int pos,int x)
{
    if(start == end)
    {
        if(pos & 1)node[nodeNum].oddSum=x;
        else node[nodeNum].evenSum=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=Merge(node[2*nodeNum],node[2*nodeNum+1]);
}
 Data Query(int nodeNum,int start,int end,int l,int r)
{
    if(l <= start  &&  r >= end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    Data x=Query(nodeNum*2,start,mid,l,mid);
    Data y=Query(nodeNum*2+1,mid+1,end,mid+1,r);
    Data ans=Merge(x,y);
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,q,r,x,op;
    Data ans;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    cin >> q;
    while(q--)
    {
        cin >> op;
        if(!op)
        {
            cin >> l >> x;
            Update(1,1,n,l,x);
        }
        else
        {
            cin >> l >> r;
            ans=Query(1,1,n,l,r);
            if(l & 1)cout << ans.oddSum-ans.evenSum << '\n';
            else cout << ans.evenSum-ans.oddSum << '\n';
        }
    }
    return 0;
}
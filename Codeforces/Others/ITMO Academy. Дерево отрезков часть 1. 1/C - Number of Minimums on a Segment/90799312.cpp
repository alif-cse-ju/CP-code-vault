#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+2];
pair<int,int>node[4*N+2];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum].first=a[l];
        node[nodeNum].second=1;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    if(node[2*nodeNum].first == node[2*nodeNum+1].first)
    {
        node[nodeNum].first=node[2*nodeNum].first;
        node[nodeNum].second=node[2*nodeNum].second + node[2*nodeNum+1].second;
    }
    else if(node[2*nodeNum].first < node[2*nodeNum+1].first)node[nodeNum]=node[2*nodeNum];
    else node[nodeNum]=node[2*nodeNum+1];
void Update(int nodeNum,int start,int end,int pos,int x)
    if(start == end)
    {
        node[nodeNum].first=x;
        node[nodeNum].second=1;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    if(node[2*nodeNum].first == node[2*nodeNum+1].first)
    {
        node[nodeNum].first=node[2*nodeNum].first;
        node[nodeNum].second=node[2*nodeNum].second + node[2*nodeNum+1].second;
    }
    else if(node[2*nodeNum].first < node[2*nodeNum+1].first)node[nodeNum]=node[2*nodeNum];
    else node[nodeNum]=node[2*nodeNum+1];
}
 pair<int,int>Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    pair<int,int>x=Query(nodeNum*2,start,mid,l,mid);
    pair<int,int>y=Query(nodeNum*2+1,mid+1,end,mid+1,r);
    if(x.first == y.first)return {x.first,x.second+y.second};
    else if(x.first < y.first)return x;
    else return y;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,q,r,op;
    pair<int,int>ans;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    while(q--)
    {
        cin >> op >> l >> r;
        ++l;
        if(op == 1)Update(1,1,n,l,r);
        else
        {
            ans=Query(1,1,n,l,r);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
    return 0;
}
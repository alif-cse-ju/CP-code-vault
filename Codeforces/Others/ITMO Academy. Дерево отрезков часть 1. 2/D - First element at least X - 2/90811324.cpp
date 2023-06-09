#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+2],node[4*N+2],range[4*N+2];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=a[l];
        range[nodeNum]=l;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    range[nodeNum]=range[(nodeNum << 1)+1];
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
void Update(int nodeNum,int start,int end,int pos,int x)
    if(start == end)
    {
        node[nodeNum]=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
int Query(int nodeNum,int start,int end,int idx,int val)
    if(start == end)return start;
    int mid=(start+end) >> 1,lChild=nodeNum << 1,rChild=lChild+1,x,y;
    if(range[lChild] < idx  ||  node[lChild] < val)x=0;
    else x=Query(lChild,start,mid,idx,val);
    if(x > 0)return x;
    if(node[rChild] < val)y=0;
    else y=Query(rChild,mid+1,end,idx,val);
    return y;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,x,op;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    while(q--)
    {
        cin >> op >> i >> x;
        if(op == 1)Update(1,1,n,++i,x);
        else
        {
            if(node[1] < i)cout << "-1\n";
            else cout << Query(1,1,n,++x,i)-1 << '\n';
        }
    }
    return 0;
}
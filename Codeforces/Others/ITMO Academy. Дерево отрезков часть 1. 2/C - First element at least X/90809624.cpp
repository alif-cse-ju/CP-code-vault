#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+2],node[4*N+2];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
void Update(int nodeNum,int start,int end,int pos,int x)
    if(start == end)
    {
        node[nodeNum]=a[pos]=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
int Query(int nodeNum,int start,int end,int val)
    if(start == end)return start;
    int mid=(start+end) >> 1;
    if(val <= node[nodeNum << 1])return Query(nodeNum*2,start,mid,val);
    return Query(nodeNum*2+1,mid+1,end,val);
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
        cin >> op;
        if(op == 1)cin >> i >> x,Update(1,1,n,++i,x);
        else
        {
            cin >> x;
            if(node[1] < x)cout << "-1\n";
            else cout << Query(1,1,n,x)-1 << '\n';
        }
    }
    return 0;
}
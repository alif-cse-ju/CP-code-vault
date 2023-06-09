#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long node[4*N+2];
void Update(int nodeNum,int start,int end,int pos,int x)
    if(start == end)
    {
        node[nodeNum]+=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=node[2*nodeNum] + node[2*nodeNum+1];
long long Query(int nodeNum,int start,int end,int l,int r)
    if(start >= l  &&  end <= r)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return Query(nodeNum*2,start,mid,l,mid) + Query(nodeNum*2+1,mid+1,end,mid+1,r);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,n,q,r,x,op;
    cin >> n >> q;
    while(q--)
    {
        cin >> op;
        if(op == 2)
        {
            cin >> x;
            cout << Query(1,1,n,1,++x) << '\n';
        }
        else
        {
            cin >> l >> r >> x;
            Update(1,1,n,++l,x);
            if(r < n)Update(1,1,n,++r,-x);
        }
    }
    return 0;
}
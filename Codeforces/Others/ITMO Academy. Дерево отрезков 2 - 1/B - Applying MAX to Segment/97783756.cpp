#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int node[4*N];
void Update(int nodeNum,int start,int end,int l,int r,int x)
    if(start >= l &&  end <= r)
    {
        node[nodeNum]=max(x,node[nodeNum]);
        return;
    }
    int mid=(start+end) >> 1;
    if(r <= mid)Update(2*nodeNum,start,mid,l,r,x);
    else if(l > mid)Update(2*nodeNum+1,mid+1,end,l,r,x);
    else
    {
        Update(2*nodeNum,start,mid,l,mid,x);
        Update(2*nodeNum+1,mid+1,end,mid+1,r,x);
    }
int Query(int nodeNum,int start,int end,int l)
    if(start == end)return node[nodeNum];
    int mid=(start+end) >> 1,res;
    if(l <= mid)res=Query(nodeNum*2,start,mid,l);
    else res=Query(nodeNum*2+1,mid+1,end,l);
    return max(res,node[nodeNum]);
int main()
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
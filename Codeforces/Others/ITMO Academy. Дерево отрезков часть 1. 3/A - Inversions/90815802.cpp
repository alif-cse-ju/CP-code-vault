#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+2],node[4*N+2];
void Update(int nodeNum,int start,int end,int pos)
    if(start == end)
    {
        node[nodeNum]=1;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos);
    else Update(2*nodeNum+1,mid+1,end,pos);
    node[nodeNum]=node[2*nodeNum] + node[2*nodeNum+1];
int Query(int nodeNum,int start,int end,int l,int r)
    if(l > r)return 0;
    if(start >= l  &&  end <= r)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(2*nodeNum,start,mid,l,r);
    else if(l > mid)return Query(2*nodeNum+1,mid+1,end,l,r);
    return Query(2*nodeNum,start,mid,l,mid)+Query(2*nodeNum+1,mid+1,end,mid+1,r);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        cout << Query(1,1,n,a[i]+1,n) << ' ';
        Update(1,1,n,a[i]);
    }
    return 0;
}
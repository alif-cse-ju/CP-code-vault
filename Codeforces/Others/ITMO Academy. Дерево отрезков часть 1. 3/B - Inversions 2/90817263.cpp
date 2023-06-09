#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+2],node[4*N+2];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=1;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=node[2*nodeNum] + node[2*nodeNum+1];
void Update(int nodeNum,int start,int end,int pos)
    if(start == end)
    {
        node[nodeNum]=0;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos);
    else Update(2*nodeNum+1,mid+1,end,pos);
    node[nodeNum]=node[2*nodeNum] + node[2*nodeNum+1];
int Query(int nodeNum,int start,int end,int val)
    if(start == end)return start;
    int mid=(start+end) >> 1;
    if(val > node[2*nodeNum+1])return Query(2*nodeNum,start,mid,val-node[2*nodeNum+1]);
    return Query(2*nodeNum+1,mid+1,end,val);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x;
    cin >> n;
    Build(1,1,n);
    int ans[n+2];
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=n;i>0;i--)
    {
        x=Query(1,1,n,a[i]+1);
        Update(1,1,n,x);
        ans[i]=x;
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N+2],ans[N+2],lft[N+2],node[4*N+2];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=0;
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=node[2*nodeNum] + node[2*nodeNum+1];
void Update(int nodeNum,int start,int end,int pos,int val)
    if(start == end)
    {
        node[nodeNum]=val;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,val);
    else Update(2*nodeNum+1,mid+1,end,pos,val);
    node[nodeNum]=node[2*nodeNum] + node[2*nodeNum+1];
int Query(int nodeNum,int start,int end,int l,int r)
    if(start >= l  &&  end <= r)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(2*nodeNum,start,mid,l,r);
    else if(l > mid)return Query(2*nodeNum+1,mid+1,end,l,r);
    return Query(2*nodeNum,start,mid,l,mid) + Query(2*nodeNum+1,mid+1,end,mid+1,r);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    cin >> n;
    n <<= 1;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        if(!lft[a[i]])
        {
            lft[a[i]]=i;
            Update(1,1,n,lft[a[i]],1);
        }
        else
        {
            ans[a[i]]=Query(1,1,n,lft[a[i]]+1,i);
            Update(1,1,n,lft[a[i]],0);
            lft[a[i]]=0;
        }
    }
    Build(1,1,n);
    reverse(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        if(!lft[a[i]])
        {
            lft[a[i]]=i;
            Update(1,1,n,lft[a[i]],1);
        }
        else
        {
            ans[a[i]]+=Query(1,1,n,lft[a[i]]+1,i);
            Update(1,1,n,lft[a[i]],0);
            lft[a[i]]=0;
        }
    }
    n >>= 1;
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}
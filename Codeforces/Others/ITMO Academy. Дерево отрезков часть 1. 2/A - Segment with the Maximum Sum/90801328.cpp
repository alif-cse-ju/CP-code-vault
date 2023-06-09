#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct Data
    long long totalSum,maxSum,preSum,sufSum;
    Data()
    {
        totalSum=maxSum=preSum=sufSum=0;
    }
int a[N+2];
Data node[4*N+2];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum].preSum=a[l];
        node[nodeNum].sufSum=a[l];
        node[nodeNum].maxSum=a[l];
        node[nodeNum].totalSum=a[l];
        return;
    }
    int mid=(l+r) >> 1,lChild=nodeNum << 1,rChild=lChild+1;
    Build(lChild,l,mid);
    Build(rChild,mid+1,r);
    node[nodeNum].totalSum=node[lChild].totalSum+node[rChild].totalSum;
    node[nodeNum].maxSum=max(max(node[lChild].maxSum,node[rChild].maxSum),node[lChild].sufSum+node[rChild].preSum);
    node[nodeNum].preSum=max(node[lChild].totalSum+node[rChild].preSum,node[lChild].preSum);
    node[nodeNum].sufSum=max(node[lChild].sufSum+node[rChild].totalSum,node[rChild].sufSum);
void Update(int nodeNum,int start,int end,int pos,int x)
{
    if(start == end)
    {
        node[nodeNum].preSum=x;
        node[nodeNum].sufSum=x;
        node[nodeNum].maxSum=x;
        node[nodeNum].totalSum=x;
        return;
    }
    int mid=(start+end) >> 1,lChild=nodeNum << 1,rChild=lChild+1;
    if(pos <= mid)Update(lChild,start,mid,pos,x);
    else Update(rChild,mid+1,end,pos,x);
    node[nodeNum].totalSum=node[lChild].totalSum+node[rChild].totalSum;
    node[nodeNum].maxSum=max(max(node[lChild].maxSum,node[rChild].maxSum),node[lChild].sufSum+node[rChild].preSum);
    node[nodeNum].preSum=max(node[lChild].totalSum+node[rChild].preSum,node[lChild].preSum);
    node[nodeNum].sufSum=max(node[lChild].sufSum+node[rChild].totalSum,node[rChild].sufSum);
}
 Data Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1,lChild=nodeNum << 1,rChild=lChild+1;
    if(r <= mid)return Query(lChild,start,mid,l,r);
    if(mid < l)return Query(rChild,mid+1,end,l,r);
    Data ans;
    Data x=Query(lChild,start,mid,l,mid);
    Data y=Query(rChild,mid+1,end,mid+1,r);
    ans.totalSum=x.totalSum+y.totalSum;
    ans.maxSum=max(max(x.maxSum,y.maxSum),x.sufSum+y.preSum);
    ans.preSum=max(x.totalSum+y.preSum,x.preSum);
    ans.sufSum=max(x.sufSum+y.totalSum,y.sufSum);
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    Data ans;
    int i,n,q,x;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    ans=Query(1,1,n,1,n);
    cout << max(0LL,ans.maxSum) << '\n';
    while(q--)
    {
        cin >> i >> x;
        Update(1,1,n,i+1,x);
        ans=Query(1,1,n,1,n);
        cout << max(0LL,ans.maxSum) << '\n';
    }
    return 0;
}
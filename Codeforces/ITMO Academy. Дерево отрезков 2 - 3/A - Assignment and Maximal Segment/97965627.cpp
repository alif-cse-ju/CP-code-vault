#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
 long long preSum[4*N+2],sufSum[4*N+2],sum[4*N+2],maxSum[4*N+2],lazy[4*N+2];
 void Propagate(int nodeNum,int l,int r)
{
    if(lazy[nodeNum] == LLONG_MIN)return;
    sum[nodeNum]=(r-l+1)*lazy[nodeNum];
    if(lazy[nodeNum] > 0)preSum[nodeNum]=sufSum[nodeNum]=maxSum[nodeNum]=(r-l+1)*lazy[nodeNum];
    else preSum[nodeNum]=sufSum[nodeNum]=maxSum[nodeNum]=0;
    if(l != r)
    {
        lazy[nodeNum*2]=lazy[nodeNum];
        lazy[nodeNum*2 + 1]=lazy[nodeNum];
    }
    lazy[nodeNum]=LLONG_MIN;
}
 void Update(int nodeNum,int start,int end,int l,int r,long long value)
{
    if(lazy[nodeNum] != LLONG_MIN)
    {
        sum[nodeNum]=(end-start+1)*lazy[nodeNum];
        if(lazy[nodeNum] > 0)preSum[nodeNum]=sufSum[nodeNum]=maxSum[nodeNum]=(end-start+1)*lazy[nodeNum];
        else preSum[nodeNum]=sufSum[nodeNum]=maxSum[nodeNum]=0;
        if(start != end)
        {
            lazy[nodeNum*2]=lazy[nodeNum];
            lazy[nodeNum*2 + 1]=lazy[nodeNum];
        }
        lazy[nodeNum]=LLONG_MIN;
    }
    if(start >= l  &&  end <= r)
    {
        sum[nodeNum]=(end-start+1)*value;
        if(value > 0)preSum[nodeNum]=sufSum[nodeNum]=maxSum[nodeNum]=(end-start+1)*value;
        else preSum[nodeNum]=sufSum[nodeNum]=maxSum[nodeNum]=0;
        if(start != end)
        {
            lazy[nodeNum*2]=value;
            lazy[nodeNum*2 + 1]=value;
        }
        return;
    }
     int mid=(start+end) >> 1;
    if(r <= mid)
    {
        Update(2*nodeNum,start,mid,l,r,value);
        Propagate(2*nodeNum+1,mid+1,end);
    }
    else if(l > mid)
    {
        Update(2*nodeNum+1,mid+1,end,l,r,value);
        Propagate(2*nodeNum,start,mid);
    }
    else
    {
        Update(2*nodeNum,start,mid,l,mid,value);
        Update(2*nodeNum+1,mid+1,end,mid+1,r,value);
    }
    sum[nodeNum]=sum[2*nodeNum] + sum[2*nodeNum+1];
    preSum[nodeNum]=max(preSum[2*nodeNum],sum[2*nodeNum]+preSum[2*nodeNum+1]);
    sufSum[nodeNum]=max(sufSum[2*nodeNum+1],sum[2*nodeNum+1]+sufSum[2*nodeNum]);
    maxSum[nodeNum]=max(max(sum[nodeNum],sufSum[2*nodeNum]+preSum[2*nodeNum+1]),max(maxSum[2*nodeNum],maxSum[2*nodeNum+1]));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,n,r,x;
    cin >> n >> m;
    for(i=1;i<=4*n;i++)lazy[i]=LLONG_MIN;
    while(m--)
    {
        cin >> l >> r >> x;
        Update(1,1,n,++l,r,x);
        cout << maxSum[1] << '\n';
    }
    return 0;
}
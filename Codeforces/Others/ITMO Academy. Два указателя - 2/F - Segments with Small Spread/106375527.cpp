#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long a[N],maxNode[4*N],minNode[4*N];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        maxNode[nodeNum]=minNode[nodeNum]=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    maxNode[nodeNum]=max(maxNode[2*nodeNum],maxNode[2*nodeNum+1]);
    minNode[nodeNum]=min(minNode[2*nodeNum],minNode[2*nodeNum+1]);
long long MaxQuery(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return maxNode[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return MaxQuery(nodeNum*2,start,mid,l,r);
    if(mid < l)return MaxQuery(nodeNum*2+1,mid+1,end,l,r);
    return max(MaxQuery(nodeNum*2,start,mid,l,mid),MaxQuery(nodeNum*2+1,mid+1,end,mid+1,r));
long long MinQuery(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return minNode[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return MinQuery(nodeNum*2,start,mid,l,r);
    if(mid < l)return MinQuery(nodeNum*2+1,mid+1,end,l,r);
    return min(MinQuery(nodeNum*2,start,mid,l,mid),MinQuery(nodeNum*2+1,mid+1,end,mid+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,r;
    long long k,ans=0,mn,mx;
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    for(l=r=1;r<=n;r++)
    {
        while(l <= r)
        {
            mx=MaxQuery(1,1,n,l,r);
            mn=MinQuery(1,1,n,l,r);
            if(mx-mn <= k)break;
            ++l;
        }
        ans+=(r-l+1);
    }
    cout << ans;
    return 0;
}
//
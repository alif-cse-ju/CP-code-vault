#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int mn[N],mx[N],sum[N],mnTree[4*N],mxTree[4*N];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        mnTree[nodeNum]=mxTree[nodeNum]=sum[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    mnTree[nodeNum]=min(mnTree[2*nodeNum],mnTree[2*nodeNum+1]);
    mxTree[nodeNum]=max(mxTree[2*nodeNum],mxTree[2*nodeNum+1]);
int MaxQuery(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return mxTree[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return MaxQuery(nodeNum*2,start,mid,l,r);
    if(mid < l)return MaxQuery(nodeNum*2+1,mid+1,end,l,r);
    return max(MaxQuery(nodeNum*2,start,mid,l,mid),MaxQuery(nodeNum*2+1,mid+1,end,mid+1,r));
int MinQuery(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return mnTree[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return MinQuery(nodeNum*2,start,mid,l,r);
    if(mid < l)return MinQuery(nodeNum*2+1,mid+1,end,l,r);
    return min(MinQuery(nodeNum*2,start,mid,l,mid),MinQuery(nodeNum*2+1,mid+1,end,mid+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,q,l,r,curMn,curMx;
    cin >> t;
    while(t--)
    {
        cin >> n >> q >> s+1;
        for(i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+(s[i] == '+' ? 1 : -1);
            mn[i]=min(mn[i-1],sum[i]),mx[i]=max(mx[i-1],sum[i]);
        }
        Build(1,1,n);
        while(q--)
        {
            cin >> l >> r;
            curMn=mn[l-1],curMx=mx[l-1];
            if(r < n)
            {
                curMn=min(curMn,MinQuery(1,1,n,r+1,n)-sum[r]+sum[l-1]);
                curMx=max(curMx,MaxQuery(1,1,n,r+1,n)-sum[r]+sum[l-1]);
            }
            cout << curMx-curMn+1 << '\n';
        }
    }
    return 0;
}
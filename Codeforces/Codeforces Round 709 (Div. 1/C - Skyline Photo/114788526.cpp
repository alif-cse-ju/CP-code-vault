#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
int b[N],h[N];
long long dp[N],node[4*N];
void Update(int nodeNum,int start,int end,int pos,long long x)
    if(start == end)
    {
        node[nodeNum]=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
long long Query(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return max(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
 int main()
{
    FAST();
    int i,l,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> h[i];
    for(i=1;i<=n;i++)cin >> b[i];
    dp[1]=b[1];
    deque<int>dq;
    dq.emplace_back(0);
    dq.emplace_back(1);
    Update(1,1,n,1,dp[1]);
    for(i=2;i<=n;i++)
    {
        while(h[dq.back()] > h[i])dq.pop_back();
        if(dq.back() == 0)dp[i]=b[i];
        else dp[i]=dp[dq.back()];
        dp[i]=max(dp[i],Query(1,1,n,max(1,dq.back()),i-1)+b[i]);
        Update(1,1,n,i,dp[i]);
        dq.emplace_back(i);
    }
    cout << dp[n];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int n,a[N],maxF[N],maxR[N],node[4*N];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
void Update(int nodeNum,int start,int end,int pos,int x)
    if(start == end)
    {
        node[nodeNum]=x;
        return;
    }
    int mid=(start+end) >> 1;
    if(pos <= mid)Update(2*nodeNum,start,mid,pos,x);
    else Update(2*nodeNum+1,mid+1,end,pos,x);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
int Query(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return min(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
 void Solve()
{
    Build(1,1,n);
    int i,l,m,r,x,y;
    for(i=1;i<n;i++)
    {
        x=maxF[i];
        l=i+2,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            y=Query(1,1,n,i+1,m-1);
            if(maxR[m] == x  &&  y == x)
            {
                cout << "YES\n";
                cout << i << ' ' << m-i-1 << ' ' << n-m+1 << '\n';
                return;
            }
            if(y < x)r=m-1;
            else if(y > x)l=m+1;
            if(maxR[m] < x)r=m-1;
            else if(maxR[m] > x)l=m+1;
        }
    }
    cout << "NO\n";
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        maxF[0]=maxR[n+1]=0;
        for(i=1;i<=n;i++)maxF[i]=max(maxF[i-1],a[i]);
        for(i=n;i>0;i--)maxR[i]=max(maxR[i+1],a[i]);
        Solve();
    }
    return 0;
}
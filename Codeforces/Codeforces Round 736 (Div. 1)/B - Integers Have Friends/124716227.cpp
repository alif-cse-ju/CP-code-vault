#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
ll a[N],node[4*N];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=__gcd(node[2*nodeNum],node[2*nodeNum+1]);
ll Query(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return __gcd(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
bool Check(int sz,const int& n)
    int i;
    for(i=sz;i<=n;i++)
    {
        if(Query(1,1,n,i-sz+1,i) != 1)return 1;
    }
    return 0;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,l,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        if(n == 1)
        {
            cout << "1\n";
            continue;
        }
        for(i=1;i<n;i++)a[i]=abs(a[i+1]-a[i]);
        Build(1,1,--n);
        ans=0,l=1,r=n;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(Check(m,n))ans=m,l=m+1;
            else r=m-1;
        }
        cout << ans+1 << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long a[N],node[4*N];
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
long long Query(int nodeNum,int start,int end,int l,int r)
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return __gcd(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long gcd;
    int i,l,n,r,ans=INT_MAX;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    for(l=r=1;r<=n;r++)
    {
        while(l <= r)
        {
            gcd=Query(1,1,n,l,r);
            if(gcd > 1LL)break;
            ++l;
        }
        if(l > r)ans=1;
        else
        {
            gcd=Query(1,1,n,max(1,l-1),r);
            if(gcd == 1LL)ans=min(ans,r-l+2);
        }
    }
    if(ans == INT_MAX)cout << "-1";
    else cout << ans;
    return 0;
}
//
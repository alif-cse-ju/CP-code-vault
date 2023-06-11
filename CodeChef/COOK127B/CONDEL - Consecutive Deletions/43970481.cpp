#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],node[4*N];
void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=node[2*nodeNum]+node[2*nodeNum+1];
}
long long Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return Query(nodeNum*2,start,mid,l,mid)+Query(nodeNum*2+1,mid+1,end,mid+1,r);
}
int main()
{
    FAST();
    int i,k,n,t;
    long long ans,cnt,mn;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans=cnt=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            cnt+=a[i];
        }
        Build(1,1,n);
        mn=LLONG_MAX;
        for(i=k;i<=n;i++)mn=min(mn,Query(1,1,n,i-k+1,i));
        ans=(mn*(mn+1ll))/2ll+cnt-mn;
        cout << ans << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],b[N],node[4*N];
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
int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return __gcd(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n,r,t,ans,gcd,tmp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=gcd=0;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            gcd=__gcd(a[i],gcd);
        }
        Build(1,1,n);
        for(i=1;i<=n;i++)
        {
            l=1,r=n;
            while(l <= r)
            {
                m=(l+r) >> 1;
                if(i+m-1 <= n)tmp=Query(1,1,n,i,i+m-1);
                else tmp=__gcd(Query(1,1,n,i,n),Query(1,1,n,1,m-(n-i+1)));
                if(tmp == gcd)r=m-1;
                else l=m+1;
            }
            ans=max(ans,r);
        }
        cout << ans << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
long long c[N];
int a[N],dist[N],dp[N][20];
void Update(int cur,int par)
    dist[cur]=dist[par]+1;
    dp[cur][0]=par;
    for(int i=1;i<20;i++)dp[cur][i]=dp[dp[cur][i-1]][i-1];
int FindKth(int node,int k)
    for(int i=19;i>=0;i--)
    {
        if((1 << i) <= k)
        {
            k-=(1 << i);
            node=dp[node][i];
        }
    }
    return node;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long cost,weight;
    int cnt=1,i,l,m,p,q,r,x,y,z;
    map<int,int>node;
    node[1]=1;
    cin >> q >> a[1] >> c[1];
    for(i=1;i<=q;i++)
    {
        cin >> z;
        if(z == 1)
        {
            cin >> p >> x >> y;
            node[i+1]=++cnt;
            a[cnt]=x,c[cnt]=y;
            Update(cnt,node[p+1]);
        }
        else
        {
            cin >> x >> y;
            x=node[x+1];
            cost=weight=0;
            while(y  &&  a[x])
            {
                l=0,r=dist[x];
                while(l <= r)
                {
                    m=(l+r) >> 1;
                    p=FindKth(x,m);
                    if(a[p] > 0)z=p,l=m+1;
                    else r=m-1;
                }
                p=z,z=min(y,a[p]),y-=z,a[p]-=z,cost+=z*c[p],weight+=z;
            }
            cout << weight << ' ' << cost << endl;
        }
    }
    return 0;
}
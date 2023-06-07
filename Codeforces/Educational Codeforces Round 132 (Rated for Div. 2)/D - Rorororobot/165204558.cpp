#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll a[M],node[4*M];
void Build(int nodeNum,int l,int r)
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }
    int m=(l+r)>>1;
    Build(2*nodeNum,l,m), Build(2*nodeNum+1,m+1,r);
    node[nodeNum]=max(node[2*nodeNum], node[2*nodeNum+1]);
ll Query(int nodeNum,int start,int end,int l,int r)
{
    if(l > r)return 0;
    if(start >= l  &&  end <= r)return node[nodeNum];
    int m=(start+end) >> 1;
    if(r <= m)return Query(2*nodeNum,start,m,l,r);
    else if(l > m)return Query(2*nodeNum+1,m+1,end,l,r);
    return max(Query(2*nodeNum,start,m,l,r), Query(2*nodeNum+1,m+1,end,l,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n;cin >> n >> m;
    for(int i=1;i<=m;i++)cin >> a[i];
    Build(1,1,m);
    int q;cin >> q;
    while(q--)
    {
        ll k,x1,x2,y1,y2;cin >> x1 >> y1 >> x2 >> y2 >> k;
        if(abs(x1-x2)%k  ||  abs(y1-y2)%k)cout << "NO\n";
        else
        {
            ll mx=Query(1,1,m,min(y1,y2),max(y1,y2));
            if(x1 > mx)
            {
                cout << "YES\n";
                continue;
            }
            x1 = mx+k-(mx-x1)%k;
            if(x1 <= n)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
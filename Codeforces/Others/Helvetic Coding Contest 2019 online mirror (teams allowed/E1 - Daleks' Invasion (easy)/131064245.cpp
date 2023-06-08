#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int p[M];
tuple<int,int,int>edges[N];
int FindParent(int i)
    if(p[i] == i)return i;
    return p[i]=FindParent(p[i]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,m,n,px,py,x,y,z;
    cin >> n >> m;
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        edges[i]=make_tuple(z,x,y);
    }
    if(m > 1)sort(edges+2,edges+m+1);
    ans=1e9;
    auto [z1,x1,y1]=edges[1];
    for(i=2;i<=m;i++)
    {
        auto [z,x,y]=edges[i];
        px=FindParent(x), py=FindParent(y);
        if(px != py)p[py]=px;
        px=FindParent(x1), py=FindParent(y1);
        if(px == py)
        {
            ans=z;
            break;
        }
    }
    cout << ans;
    return 0;
}
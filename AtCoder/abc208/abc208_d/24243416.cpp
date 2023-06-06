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

const int M=4e2+5;
const int N=2e5+5;
const int mod=1e9+7;

ll dist[M][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,j,k,m,n,x,y,z;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)dist[i][j]=(i == j ? 0 : 1e9+5);
    }
    while(m--)cin >> x >> y >> z,dist[x][y]=z;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)ans+=(dist[i][j] < 1e9 ? dist[i][j] : 0);
        }
    }
    cout << ans;
    return 0;
}

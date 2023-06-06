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

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const ll sz = 305;

ll dist[sz][sz];

void Cal(const int& n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0,i,j,m,n,x,y,z;
    cin >> n >> m;
    vector<tuple<int,int,int>>edges;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)dist[i][j]=1e12;
        dist[i][i]=0;
    }
    while(m--)
    {
        cin >> x >> y >> z;
        edges.emplace_back(z,x,y);
        dist[x][y]=dist[y][x]=z;
    }
    Cal(n);
    for(auto [z,x,y] : edges)
    {
        for(i=1;i<=n;i++)
        {
            if(i == x  ||  i == y)continue;
            if(dist[x][i]+dist[i][y] <= z)
            {
                ++ans;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e3+5;
const int mod=1e9+7;

bool visited[N];
vector<int>adj[N];

void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1;
    for(int y : adj[x])DFS(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,x,y,ans=0;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)visited[j]=0;
        DFS(i);
        for(j=1;j<=n;j++)ans+=visited[j];
    }
    cout << ans;
    return 0;
}

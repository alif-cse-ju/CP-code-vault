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

int L[M],R[M],cnt;
vector<int>adj[M];

void DFS(int x,int p)
{
    if((int)adj[x].size() == 1  &&  x > 1)
    {
        L[x]=R[x]=++cnt;
    }
    for(int y : adj[x])
    {
        if(p ^ y)
        {
            DFS(y,x);
            L[x]=min(L[x],L[y]);
            R[x]=max(R[x],R[y]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y;
    cin >> n;
    for(i=1;i<=n;i++)L[i]=1e9, R[i]=-1;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    DFS(1,0);
    for(i=1;i<=n;i++)cout << L[i] << ' ' << R[i] << '\n';
    return 0;
}

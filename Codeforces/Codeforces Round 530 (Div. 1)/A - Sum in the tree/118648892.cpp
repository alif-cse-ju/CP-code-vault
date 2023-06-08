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
vector<int>adj[M];
int a[M],b[M],lvl[M];
void DFS(int x,int p)
    lvl[x]=lvl[p]+1;
    if(lvl[x]%2 == 0)
    {
        if(a[x] >= 0)
        {
            cout << "-1";
            exit(0);
        }
        a[x]=INT_MAX;
        for(int y : adj[x])a[x]=min(a[x],a[y]);
        if(a[x] == INT_MAX)a[x]=-1;
        a[x]=max(a[p],a[x]);
    }
    else
    {
        if(a[x] < a[p])
        {
            cout << "-1";
            exit(0);
        }
    }
    b[x]=a[x]-a[p];
    for(int y : adj[x])DFS(y,x);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x;
    long long ans=0;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> x;
        adj[x].emplace_back(i);
    }
    for(i=1;i<=n;i++)cin >> a[i];
    b[1]=a[1];
    DFS(1,0);
    for(i=1;i<=n;i++)ans+=b[i];
    cout << ans;
    return 0;
}
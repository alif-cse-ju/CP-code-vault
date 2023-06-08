#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int ans[M];
vector<pair<int,int>>adj[M];
int DFS(int x,int p,const int& v)
    int cnt=((int)adj[x].size() > v);
    for(auto [y,i] : adj[x])
    {
        if(p ^ y)cnt += DFS(y,x,v);
    }
    return cnt;
void DFS2(int x,int p,const int& v)
    int c=0;
    if(p)
    {
        for(auto [y,i] : adj[x])
        {
            if(y == p)
            {
                c=ans[i];
                break;
            }
        }
    }
    if((int)adj[x].size() > v)
    {
        for(auto [y,i] : adj[x])ans[i]=max(1,c);
    }
    else
    {
        int ii=1;
        for(auto [y,i] : adj[x])
        {
            if(p ^ y)
            {
                if(ii == c)++ii;
                ans[i]=ii++;
            }
        }
    }
    for(auto [y,i] : adj[x])
    {
        if(p ^ y)DFS2(y,x,v);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,k,m,n,r,x,y;
    cin >> n >> k;
    for(i=1;i<n;i++)
    {
        cin >> x >> y;
        adj[x].emplace_back(y,i);
        adj[y].emplace_back(x,i);
    }
    l=1,r=n-1;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(DFS(1,0,m) <= k)r=m-1;
        else l=m+1;
    }
    cout << r+1 << '\n';
    DFS2(1,0,r+1);
    for(i=1;i<n;i++)cout << ans[i] << ' ';
    return 0;
}
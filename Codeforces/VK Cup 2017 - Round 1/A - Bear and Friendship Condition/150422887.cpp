#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
ll sum;
int cnt;
bool visited[M];
vector<int>adj[M];
void DFS(int x)
    ++cnt, sum+=(int)adj[x].size(), visited[x]=1;
    for(int y : adj[x])
    {
        if(!visited[y])DFS(y);
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x,y;
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cnt=sum=0;
            DFS(i);
            sum /= 2;
            if((1ll*cnt*(cnt-1))/2 != sum)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
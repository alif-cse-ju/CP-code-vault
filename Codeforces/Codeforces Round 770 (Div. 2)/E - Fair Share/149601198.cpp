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
int in[M+M];
string ans[M+M];
vector<pair<int,int>>adj[M+M];
void DFS(int x)
    if(!in[x])
    {
        for(int i=0;i<(int)adj[x].size();i++)ans[x] += 'L';
    }
    while(in[x] < (int)adj[x].size())
    {
        auto [v,idx] = adj[x][in[x]];
        if(v == -1)++in[x];
        else
        {
            adj[v][idx].first=adj[x][in[x]].first=-1;
            if(x < M)ans[x][in[x]]='R';
            ++in[x], DFS(v);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d=0,i,m,n,x;
    map<int,int>occ,distVals;
    cin >> m;
    for(i=0;i<m;i++)
    {
        cin >> n;
        while(n--)
        {
            cin >> x;
            if(distVals.find(x) == distVals.end())distVals[x]=d++;
            x=distVals[x], ++occ[x];
            adj[i].emplace_back(x+M,(int)adj[x+M].size());
            adj[x+M].emplace_back(i,(int)adj[i].size()-1);
        }
    }
    for(auto [x,y] : occ)
    {
        if(y & 1)
        {
            cout << "NO";
            return 0;
        }
    }
    for(i=0;i<M+M;i++)DFS(i);
    cout << "YES\n";
    for(i=0;i<m;i++)cout << ans[i] << '\n';
    return 0;
}
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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
vector<int>adj[M];
int par[M],s,tag[M];
void DFS(int x,int t)
    tag[x]=t;
    for(int y : adj[x])
    {
        if(tag[y])
        {
            if(tag[y] == t)continue;
            cout << "Possible\n";
            vector<int>pathA,pathB;
            pathA.emplace_back(y);
            while(x != s)pathA.emplace_back(x), x=par[x];
            pathA.emplace_back(s);
            while(y != s)pathB.emplace_back(y), y=par[y];
            pathB.emplace_back(s);
            cout << (int)pathA.size() << '\n';
            while(!pathA.empty())cout << pathA.back() << ' ', pathA.pop_back();
            cout << '\n';
            cout << (int)pathB.size() << '\n';
            while(!pathB.empty())cout << pathB.back() << ' ', pathB.pop_back();
            exit(0);
        }
        else par[y]=x, DFS(y,t);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,x,y;
    cin >> n >> m >> s;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
    }
    for(int t : adj[s])
    {
        if(tag[t])
        {
            cout << "Possible\n";
            cout << "2\n" << s << ' ' << t << '\n';
            vector<int>path;
            while(t != s)path.emplace_back(t), t=par[t];
            path.emplace_back(s);
            cout << (int)path.size() << '\n';
            while(!path.empty())cout << path.back() << ' ', path.pop_back();
            return 0;
        }
        tag[s]=t, par[t]=s;
        DFS(t,t);
    }
    cout << "Impossible";
    return 0;
}
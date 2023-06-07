#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;

char s[M];
queue<int>q;
vector<int>adj[M];
bool vis1[M],vis2[M];
int cnt[M],dp[M],in[M],in2[M];

void DFS(int x)
{
    vis1[x]=vis2[x]=1;
    for(int &y : adj[x])
    {
        if(vis2[y])
        {
            cout << "-1";
            exit(0);
        }
        if(!vis1[y])DFS(y);
    }
    vis2[x]=0;
}

void TopoSort()
{
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        for(int &y : adj[x])
        {
            --in2[y], dp[y]=max(cnt[y]+dp[x], dp[y]);
            if(!in2[y])q.emplace(y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m >> s+1;
    map<pair<int,int>,bool>mark;
    bool ok=1;
    while(m--)
    {
        int x,y;cin >> x >> y;
        if(x == y)
        {
            ok=0;
            continue;
        }
        if(mark.find({x,y}) != mark.end())continue;
        adj[x].emplace_back(y), ++in[y], mark[{x,y}]=1;
    }
    if(!ok)
    {
        cout << "-1";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis1[i])DFS(i);
    }
    int ans=0;
    for(char c='a';c<='z';c++)
    {
        for(int i=1;i<=n;i++)cnt[i]=dp[i]=(s[i] == c);
        for(int i=1;i<=n;i++)in2[i]=in[i];
        for(int i=1;i<=n;i++)
        {
            if(!in2[i])q.emplace(i);
        }
        TopoSort();
        for(int i=1;i<=n;i++)ans=max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}

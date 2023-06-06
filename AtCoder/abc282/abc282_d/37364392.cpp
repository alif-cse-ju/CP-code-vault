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

const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;

vector<int>adj[M];
int cnt[M][2],color[M],gCnt,gNum[M];

void DFS(int x)
{
    gNum[x]=gCnt, ++cnt[gCnt][color[x]];
    for(int &y : adj[x])
    {
        if(color[y] == -1)color[y]=1-color[x], DFS(y);
        else if(color[y] != 1-color[x])
        {
            cout << "0";
            exit(0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    while(m--)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)color[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(color[i] == -1)++gCnt, color[i]=0, DFS(i);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans += (n-cnt[gNum[i]][0]-cnt[gNum[i]][1]) + (cnt[gNum[i]][1-color[i]]-(int)adj[i].size());
    cout << ans/2;
    return 0;
}

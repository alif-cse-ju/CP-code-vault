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

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int lvl[M];
vector<int>adj[M], leaves;

void DFS(int x,int p)
{
    lvl[x]=lvl[p]+1;
    if((int)adj[x].size() == 1)
    {
        leaves.emplace_back(lvl[x]);
        return;
    }
    for(int &y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
}

int Solve(int x)
{
    leaves.clear(), DFS(x,1);
    sort(leaves.begin(), leaves.end());
    for(int i=1;i<(int)leaves.size();i++)leaves[i]=max(leaves[i], leaves[i-1]+1);
    return leaves.back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<n;i++)
    {
        int x,y;cin >> x >> y;
        adj[x].emplace_back(y), adj[y].emplace_back(x);
    }
    int ans=0;
    for(int &it : adj[1])ans=max(ans, Solve(it));
    cout << ans;
    return 0;
}

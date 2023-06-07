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
const int mod=1e9+7;

int par[M],r[M],sz[M];
vector<int>switches[M];

int FindParent(int p)
{
    return par[p]=(par[p] == p ? p : FindParent(par[p]));
}

void Join(int x,int y)
{
    int px=FindParent(x), py=FindParent(y);
    if(px != py)
    {
        if(sz[px] >= sz[py])par[py]=px, sz[px]+=sz[py];
        else par[px]=py, sz[py]+=sz[px];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> r[i];
    for(int i=1;i<=m+m;i++)par[i]=i, sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        int k;cin >> k;
        while(k--)
        {
            int x;cin >> x;
            switches[x].emplace_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x=switches[i][0], y=switches[i][1];
        if(r[i])Join(x,y), Join(x+m,y+m);
        else Join(x,y+m), Join(x+m,y);
    }
    for(int i=1;i<=m;i++)
    {
        if(FindParent(i) == FindParent(i+m))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
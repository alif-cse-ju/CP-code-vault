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

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;

int b[M];
vector<int>adj[M];

bool cmp(const int& x,const int& y)
{
    return (int)adj[x].size() < (int)adj[y].size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=0;i<=n+1;i++)adj[i].clear();
        int k=0;
        for(int i=1;i<=n;i++)
        {
            cin >> b[i];
            if(b[i] > i)k=i;
            adj[b[i]].emplace_back(i);
        }
        vector<int>v;
        if(adj[0].empty())v.emplace_back(n+1);
        else v.emplace_back(0);
        for(int i=0;i<(int)v.size();i++)
        {
            int x=v[i];
            sort(adj[x].begin(),adj[x].end(),cmp);
            for(int &y : adj[x])v.emplace_back(y);
        }
        cout << k << '\n';
        for(int i=1;i<(int)v.size();i++)cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}

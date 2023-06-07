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
using namespace std;
const int M=3e5+5;
int need, dep;
vector<int>adj[M];
int DFS(int x,int p)
    int mxDep=1;
    for(int y : adj[x])
    {
        if(p ^ y)mxDep=max(mxDep, DFS(y,x)+1);
    }
    if(mxDep == dep)need += (p > 1), mxDep=0;
    return mxDep;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;cin >> p;
            adj[p].emplace_back(i);
        }
        int l=1,r=n-1;
        while(l <= r)
        {
            int m=(l+r) >> 1;
            need=0, dep=m;
            int tmp = DFS(1,1);
            if(need <= k)r=m-1;
            else l=m+1;
        }
        cout << r+1 << '\n';
    }
    return 0;
}
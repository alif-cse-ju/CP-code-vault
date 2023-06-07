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

int cnt;
bool visited[M];
map<int,int>eMark[M];
vector<int>adj[M],cycle;

void DFS(int x)
{
        cycle.emplace_back(x);
        for(int &y : adj[x])
        {
                if((int)adj[y].size() == 4)eMark[x][y]=eMark[y][x]=1;
        }
        for(int &y : adj[x])
        {
                if((int)adj[y].size() == 4  &&  !visited[y])
                {
                        visited[y]=1, DFS(y);
                        break;
                }
        }
}

void DFS1(int x)
{
        ++cnt;
        for(int &y : adj[x])
        {
                if(!visited[y]  &&  (int)adj[y].size() == 2)visited[y]=1, DFS1(y);
        }
}

void DFS2(int x)
{
        for(int &y : adj[x])
        {
                if(!visited[y])visited[y]=1, DFS2(y);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int m,n;cin >> n >> m;
            for(int i=1;i<=n;i++)adj[i].clear(), visited[i]=0;
            while(m--)
            {
                    int x,y;cin >> x >> y;
                    adj[x].emplace_back(y), adj[y].emplace_back(x);
            }
            bool ok=1;
            vector<int>deg4;
            for(int i=1;i<=n  &&  ok;i++)
            {
                    if((int)adj[i].size() == 2)continue;
                    else if((int)adj[i].size() == 4)deg4.emplace_back(i), eMark[i].clear();
                    else ok=0;
            }
            if((int)deg4.size() < 3)ok=0;
            else if(ok)
            {
                    cycle.clear();
                    visited[deg4[0]]=1, DFS(deg4[0]);
                    if((int)cycle.size() != (int)deg4.size())ok=0;
                    else if(eMark[cycle[0]].find(cycle.back()) == eMark[cycle[0]].end())ok=0;
                    else if(ok)
                    {
                            for(int &x : deg4)
                            {
                                    if(!ok)break;
                                    cnt=0, DFS1(x);
                                    ok &= (cnt == (int)deg4.size());
                            }
                    }
            }
            if(ok)
            {
                    for(int i=1;i<=n &&  ok;i++)ok &= visited[i], visited[i]=0;
            }
            if(ok)
            {
                    DFS2(1);
                    for(int i=1;i<=n  &&  ok;i++)ok &= visited[i];
            }
            if(ok)cout << "YES\n";
            else cout << "NO\n";
    }
    return 0;
}

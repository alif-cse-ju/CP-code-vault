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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

bool visited[M];
vector<int>divs[M],muls[M];
int a[M],dist[M],id[M],par[M],t;
priority_queue<pair<int,int>>pq;

void Dijkstra()
{
    while(!pq.empty())
    {
        auto [d,x]=pq.top(); pq.pop();
        if(x == a[t])return;
        d *= (-1);
        if(dist[x] != d)continue;
        for(int &y : divs[x])
        {
            if(dist[y]  &&  dist[y] <= dist[x]+1)continue;
            for(int &z : muls[y])
            {
                if(dist[z] > dist[x]+1)
                {
                    dist[z]=dist[x]+1;
                    if(id[z])par[z]=id[x], pq.emplace(-dist[z],z);
                }
            }
        }
    }
}

void PreCal()
{
    for(int i=2;i<M;i++)
    {
        if(visited[i])continue;
        for(int j=i;j<M;j+=i)divs[j].emplace_back(i), visited[j]=1;
        muls[i].emplace_back(i), visited[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] > 1)id[a[i]]=i;
    }
    int s;cin >> s >> t;
    if(s == t)cout << "1\n" << s;
    else if(a[s] == 1  ||  a[t] == 1)cout << "-1";
    else if(a[s] == a[t])cout << "2\n" << s << ' ' << t;
    else
    {
        id[a[s]]=s, id[a[t]]=t;
        for(int i=2;i<M;i++)
        {
            dist[i]=INT_MAX;
            if(id[i]  &&  visited[i])
            {
                for(int &j : divs[i])muls[j].emplace_back(i);
            }
        }
        dist[a[s]]=0, pq.emplace(0,a[s]), Dijkstra();
        if(dist[a[t]] == INT_MAX)cout << "-1";
        else
        {
            vector<int>path;
            while(t)path.emplace_back(t), t=par[a[t]];
            cout << (int)path.size() << '\n';
            while(!path.empty())cout << path.back() << ' ', path.pop_back();
        }
    }
    return 0;
}

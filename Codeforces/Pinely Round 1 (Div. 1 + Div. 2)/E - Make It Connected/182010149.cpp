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
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=4e6+5;
const int mod=1e9+7;
 const int mx = 4e3+5;
 bool visited[mx];
vector<int>adj[M],nodes;
 void DFS(int x)
{
    if(visited[x])return;
    visited[x]=1, nodes.emplace_back(x);
    for(int &y : adj[x])DFS(y);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)
        {
            visited[i]=0;
            adj[i].clear();
            string s;cin >> s;
            for(int j=0;j<n;j++)
            {
                if(s[j] == '1')adj[i].emplace_back(j+1);
            }
        }
        vector<int>roots;
        bool ektaiEnough=0;
        int ans,conComp=0,mnNode,mnSize=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                ++conComp, roots.emplace_back(i), nodes.clear(), DFS(i);
                if((int)nodes.size() == 1)ektaiEnough=1, ans=i;
                for(int &it : nodes)
                {
                    if((int)adj[it].size() < (int)nodes.size()-1)ektaiEnough=1, ans=it;
                }
                if(mnSize > (int)nodes.size())mnNode=i, mnSize=(int)nodes.size();
            }
        }
        if(conComp == 1)cout << "0\n";
        else if(ektaiEnough)cout << "1\n" << ans << '\n';
        else if(conComp == 2  ||  mnSize == 2)
        {
            cout << mnSize << '\n';
            nodes.clear();
            for(int i=1;i<=n;i++)visited[i]=0;
            DFS(mnNode);
            for(int &it : nodes)cout << it << ' ';
            cout << '\n';
        }
        else cout << "2\n" << roots[0] << ' ' << roots.back() << '\n';
    }
    return 0;
}
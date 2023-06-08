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
 int a[M],sz[M];
vector<int>ans,adj[M];
bool dp[M][32],dp2[M][32];
 void DFS(int x)
{
    sz[x]=1;
    for(int &y : adj[x])DFS(y), sz[x]+=sz[y];
    dp[x][a[x]]=1;
    for(int &y : adj[x])
    {
        vector<bool>dpTemp(32, 0);
        for(int i=0;i<32;i++)
        {
            if(dp[x][i])
            {
                for(int j=0;j<32;j++)
                {
                    if(dp[y][j])dpTemp[i^j]=1;
                }
            }
        }
        for(int i=0;i<32;i++)dp[x][i]=dpTemp[i];
    }
    if(!(sz[x] & 1))dp[x][0]=1;
}
 void FindAns(int x,int want)
{
    if(!want  &&  !(sz[x] & 1))
    {
        ans.emplace_back(x);
        return;
    }
    dp2[x][a[x]]=1;
    int l=(int)adj[x].size();
    vector<vector<pair<int,int>>>bapCheleRelation(l);
    for(int k=0;k<l;k++)
    {
        int y=adj[x][k];
        vector<bool>dpTemp(32,0);
        bapCheleRelation[k].resize(32);
        for(int i=0;i<32;i++)
        {
            if(dp2[x][i])
            {
                for(int j=0;j<32;j++)
                {
                    if(dp[y][j])dpTemp[i^j]=1, bapCheleRelation[k][i^j]={i,j};
                }
            }
        }
        for(int i=0;i<32;i++)dp2[x][i]=dpTemp[i];
    }
    vector<pair<int,int>>callDeyaLagbe;
    int ache=want;
    for(int i=l-1;i>=0;i--)
    {
        int y=adj[x][i];
        auto [baperHobe,chelerLagbe]=bapCheleRelation[i][ache];
        callDeyaLagbe.emplace_back(y,chelerLagbe), ache=baperHobe;
    }
    for(auto [y,wantP] : callDeyaLagbe)FindAns(y,wantP);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    int xr=0;
    for(int i=1;i<=n;i++)cin >> a[i], xr^=a[i];
    for(int i=2;i<=n;i++)
    {
        int p;cin >> p;
        adj[p].emplace_back(i);
    }
    if(!xr)cout << "1\n1";
    else if(n%2 == 0)cout << "2\n1 1";
    else
    {
        DFS(1);
        if(!dp[1][0])cout << "-1";
        else
        {
            FindAns(1,0);
            ans.emplace_back(1);
            cout << (int)ans.size() << '\n';
            for(int &it : ans)cout << it << ' ';
        }
    }
    return 0;
}
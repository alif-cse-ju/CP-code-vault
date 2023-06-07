#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
const int N=2e6+5;
const int mod=998244353;
///LCA
bool in[M];
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
    inTime[cur]=++timer;
    up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])DFS(x,cur);
    outTime[cur]=++timer;
bool IsAncestor(int x,int y)
{
    return inTime[x] <= inTime[y]  &&  outTime[x] >= outTime[y];
}
 int LCA(int x,int y)
{
    if(IsAncestor(x,y))return x;
    if(IsAncestor(y,x))return y;
    for(int i=l;i>=0;i--)
    {
        if(!IsAncestor(up[x][i],y))x=up[x][i];
    }
    return up[x][0];
}
 void PreProcess(const int& numberOfNodes)
{
    l=ceil(log2(numberOfNodes));
    for(int i=1;i<=numberOfNodes;i++)
    {
        if(!in[i])DFS(i,i);
    }
}
 ///LCA
 string ans[M];
int par[M],receiver[M];
vector<pair<int,int>>queries[M];
vector<tuple<int,int,int>>updates;
 int FindParent(int x)
{
    if(par[x] == x)return x;
    return par[x]=FindParent(par[x]);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)par[i]=i;
    int packetCnt=0,queryCnt=0;
    while(m--)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int x,y;cin >> x >> y;
            in[x]=1;
            adj[y].emplace_back(x);
            updates.emplace_back(make_tuple(1,x,y));
        }
        else if(t == 2)
        {
            int x;cin >> x;
            receiver[++packetCnt]=x;
            updates.emplace_back(make_tuple(2,x,0));
        }
        else
        {
            int i,x;cin >> x >> i;
            queries[i].emplace_back(x,++queryCnt);
        }
    }
    packetCnt=0;
    PreProcess(n);
    for(auto [t,x,y] : updates)
    {
        if(t == 1)par[x]=FindParent(y);
        else if(t == 2)
        {
            ++packetCnt;
            int x=FindParent(receiver[packetCnt]);
            for(auto [y,i] : queries[packetCnt])
            {
                if(FindParent(y) == x)
                {
                    if(LCA(receiver[packetCnt],y) == y)ans[i]="YES";
                    else ans[i]="NO";
                }
                else ans[i]="NO";
            }
        }
    }
    for(int i=1;i<=queryCnt;i++)cout << ans[i] << '\n';
    return 0;
}
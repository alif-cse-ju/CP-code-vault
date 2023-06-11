#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
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
vector<int>adj[M];
int l,timer,inTime[M],outTime[M],up[M][20];
void DFS(int cur,int par)
{
    inTime[cur]=++timer;
    up[cur][0]=par;
    for(int i=1;i<=l;i++)up[cur][i]=up[up[cur][i-1]][i-1];
    for(int x : adj[cur])
    {
        if(x ^ par)DFS(x,cur);
    }
    outTime[cur]=++timer;
}
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
    l=ceil(log2(numberOfNodes)), timer=0;
    DFS(1,1);
}
///LCA
char s[M];
int cnt[M+M][26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l >> s+1;
        for(int i=1;i<=l;i++)
        {
            adj[i].clear();
            for(int j=0;j<26;j++)cnt[i][j]=cnt[i+l][j]=0;
        }
        for(int i=1;i<l;i++)
        {
            int x,y;cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        PreProcess(l);
        for(int i=1;i<=l;i++)
        {
            cnt[inTime[i]][s[i]-'a']=1;
            cnt[outTime[i]][s[i]-'a']=-1;
        }
        for(int i=2;i<=l+l;i++)
        {
            for(int j=0;j<26;j++)cnt[i][j] += cnt[i-1][j];
        }
        int q;cin >> q;
        while(q--)
        {
            int x,y;cin >> x >> y;
            bool ok=0;
            int l=LCA(x,y);
            for(int i=0;i<26;i++)ok |= ((cnt[inTime[x]][i]-cnt[inTime[l]][i] > 0) & (cnt[inTime[y]][i]-cnt[inTime  
            if(ok)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
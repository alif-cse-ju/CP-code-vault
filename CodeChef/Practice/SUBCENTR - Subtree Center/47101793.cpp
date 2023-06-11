#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
vector <int> tree[mxN];
int depth[mxN];
int timer;
vector<int> tin,tout;
vector<vector<int>> up;
int n,l;
void dfs(int v,int p)
{
  tin[v]=++timer;
  up[v][0]=p;
  for(int i=1;i<=l;i++)
    up[v][i]=up[up[v][i-1]][i-1];
  for(int u: tree[v])
  {
    if(u!=p)
    {
      depth[u]=depth[v]+1;
      dfs(u,v);
    }
  }
  tout[v]=++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root)
{
  tin.resize(n);
  tout.resize(n);
  timer=0;
  l=ceil(log2(n));
  up.assign(n,vector<int>(l+1));
  dfs(root,root);
}
void solve()
{
  int q;
  cin>>n>>q;
  for(int i=0;i<n;i++)
  {
    tree[i].clear();
    depth[i]=0;
  }
  for(int i=0;i<n-1;i++)
  {
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  preprocess(0);
  while(q--)
  {
    int k;
    cin>>k;
    int a[k];
    int fst_node=-1,dis=-1;
    for(int i=0;i<k;i++)
    {
      cin>>a[i];
      a[i]--;
      if(depth[a[i]]>dis)
      {
        fst_node=a[i];
        dis=depth[a[i]];
      }
    }
    if(k==1)
      cout<<1<<" "<<a[0]+1<<"\n";
    else
    {
      dis=-1;
      int sec_node=-1;
      for(int i=0;i<k;i++)
      {
        int temp=depth[a[i]]+depth[fst_node]-2*depth[lca(a[i],fst_node)];
        // cout<<lca(a[i],fst_node)<<endl;
        if(temp>dis)
        {
          dis=temp;
          sec_node=a[i];
        }
      }
      if(depth[fst_node]>depth[sec_node])
          swap(fst_node,sec_node);
      int hal=dis/2;
      for(int i=l;i>=0;i--)
      {
        if(hal>=(1 << i))
        {
            hal-=(1 << i);
            sec_node=up[sec_node][i];
        }
      }
      if(dis%2==0)
        cout<<1<<" "<<sec_node+1<<"\n";
      else
        cout<<2<<" "<<min(sec_node,up[sec_node][0])+1<<" "<<max(sec_node,up[sec_node][0])+1<<"\n";
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    solve();
return 0;
}
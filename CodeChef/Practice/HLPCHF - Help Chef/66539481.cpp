#include"bits/stdc++.h"
#define int long long 
using namespace std ;
const int mxN =1e5,INF=1e9 ;
int n,k,dp[2][mxN+1],ans[2][mxN+1],c[mxN+1],pd[mxN+1]  ;
vector<int>adj[mxN+1] ;
bool s[mxN+1] ;
void dfs1(int u,int p){
  c[u]=s[u] ;
  if(s[u])
    dp[1][u]=max(dp[1][u],0LL) ;
  for(int v:adj[u]){
    if(v==p)
      continue ;
    dfs1(v,u) ;
    dp[0][u]+=dp[0][v]+c[v] ;
    dp[1][u]=max(dp[1][u],dp[1][v]+1) ;
    c[u]+=c[v] ;
  }
}
void dfs2(int u,int p){
  multiset<int>st ;
  for(int v:adj[u]){
    if(v==p)
      continue ;
    st.insert(dp[1][v]+1) ;
  }
  if(s[u])
    pd[u]=max(pd[u],0LL) ;
  for(int v:adj[u]){
    if(v==p)
      continue ;
    st.erase(st.find(dp[1][v]+1)) ;
    ans[0][v]=dp[0][v] ;
    ans[1][v]=max(dp[1][v],pd[u]+1) ;
    pd[v]=pd[u]+1 ;
    ans[0][v]+=ans[0][u]-dp[0][v]-c[v]+k-c[v] ;
    if(!st.empty()){
      int d = (*--st.end())+1 ;
      pd[v]=max(pd[v],d) ;
      ans[1][v]=max(ans[1][v],d) ;
    }
    st.insert(dp[1][v]+1) ;
    dfs2(v,u) ;
  }
}
void solve(){
  cin >> n >>k ;
  for(int i=0,x;i<k;i++){
    cin >>x ,--x ;
    s[x]=true  ;
  }
  for(int i=1,u,v;i<n;i++){
    cin >>u >> v ,--u,--v ;
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
  }
  memset(pd,0xc0,sizeof(pd)) ;
  memset(dp[1],0xc0,sizeof(dp[1])) ;
  dfs1(0,-1) ;
  ans[0][0]=dp[0][0],ans[1][0]=dp[1][0] ;
  dfs2(0,-1) ;
  int u=-1,mx=1e9 ;
  for(int i=0;i<n;i++){
    if(mx>=ans[0][i]-ans[1][i])
      mx=ans[0][i]-ans[1][i],u=i ;
  }
  cout << (k==1?n:u+1) << '\n' ;
  for(int i=0;i<n+1;i++){
    adj[i].clear() ;
    dp[0][i]=dp[1][i]=s[i]=c[i]=0 ;
    ans[0][i]=ans[1][i]=pd[i]=0 ;
  }
}
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T  ;
  cin >> T  ;
  while(T--)
    solve() ;
}
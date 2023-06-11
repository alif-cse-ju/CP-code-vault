#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<pll> vpll; 
 #define endl '\n' 
#define fast std::ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define all(v) v.begin(),v.end()
#define display(A) for(auto &aa:A) cout <<aa<<" ";cout <<"\n";
#define displayP(A) for(auto &aa:A) {display(aa);}
#define FOR(i,a,n) for(ll i=a;i<=n;i++)
#define TTT template<typename T> 
ll mp[2000010];
vll lpsx;
vll lpsy;
void z_function(string s) {
    int n = (int) s.length();
    lpsy=vector<ll> (n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            lpsy[i] = min (r - i + 1, lpsy[i - l]);
        while (i + lpsy[i] < n && s[lpsy[i]] == s[i + lpsy[i]])
            ++lpsy[i];
        if (i + lpsy[i] - 1 > r)
            l = i, r = i + lpsy[i] - 1;
    }
}
void kmp(string s){
    int n=s.size();
    lpsx=vector<ll> (n+1);
    lpsx[0]=-1;
    int i=0;
    int j=-1;
    while(i<n){
        while(j!=-1 and s[i]!=s[j]){
            j=lpsx[j];
        }
        j++;
        i++;
        lpsx[i]=j;
    }
}
void solve(){
  string s,x,y;
  cin>>x>>y>>s;
  string newx=x+"?"+s;
  string newy=y+"?"+s;
  kmp(newx);
  z_function(newy);
  int lenX=x.size();
  int lenY=y.size();
  ll ans=1;
  set<pair<ll,ll>> st;
  ll lenx=0;
  ll leny=0;
    for(int i=0;i<=lenX;i++)mp[i]=0;
  for(int i=lenX+2;i+1<lpsx.size();i++){
     int j=(i-lenX)+lenY-1;
     ll len1=lpsx[i];
     ll len2=lpsy[j+1];
         if(len1==0 or len2==0)continue;
     ll allowed=max(len2-mp[len1],0ll);
     ans+=(allowed);
     mp[len1]=max(mp[len1],len2);
  }
  char c=x[0];
  int i=0;
  int j=0;
  while(j<lenX and x[j]==c){
    j++;
  }
  ll maxi=mp[j];
  for(int k=j-2;k>=0;k--){
     ans+=max(0LL,maxi-mp[k+1]);
     maxi=max(maxi,mp[k+1]);
  }
  lenx=0;
  leny=0;
  for(int i=lenX+2;i<lpsx.size();i++){
     int j=(i-lenX)+lenY-1;
     ll len1=lpsx[i];
     ll len2=lpsy[j];
     lenx=max(lenx,len1);
     leny=max(leny,len2);
    }
  ans+=(lenx)+leny;
}
const ll MAX = 2e6 + 50, INF = 1e15; ll MOD = 1e9 + 7;
string x,s,t,S;
int k, n, m, N;
int z[MAX], pi[MAX], g[MAX], found[MAX]; 
void test_case(ll tc=0){
  cin>>s>>t>>x;
  int k = x.length(), n = s.length(), m = t.length();
  for(int i = 0; i <= max(n,m) + k + 10; i++){
    z[i] = 0, pi[i] = 0, g[i] = 0, found[i] = 0;
  }
     S = t + "?" + x;
  N = S.length();
  for (int i = 1, l = 0, r = 0; i < N; ++i) {
        if (i <= r){
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i + z[i] < N && S[z[i]] == S[i + z[i]]){
            ++z[i];
        }
        if (i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    S = s + "?" + x;
  N = S.length();
  for (int i = 1,j; i < N; i++) {
        j = pi[i-1];
        while (j > 0 && S[i] != S[j]){
            j = pi[j-1];
        }
        if (S[i] == S[j]){
            j++;
        }
         pi[i] = j;
         if(i > n){
           j = i - n;
           g[pi[i]] = max(g[pi[i]], z[j + m + 1]);
           found[pi[i]] = 1;
         }
    }
    g[0] = max(z[m + 1], g[0]);
    found[0] = 1;
    ll ans = 0;
    for(ll i = n; i >= 0; --i){
      if(!found[i]) continue;
      ans += g[i] + 1;
      found[pi[i - 1]] = 1;
      g[pi[i - 1]] = max(g[pi[i - 1]], g[i]);
    }
    cout <<ans <<"\n";
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  ll T = 1,tc=0; 
  cin>>T;
  for(;tc<T;tc++){
    test_case();  
  }
  return 0;
}
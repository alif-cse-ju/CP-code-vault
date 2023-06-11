#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
// #define int long long int
#define MOD 1000000007
#define fi first
#define se second
#define pb push_back
#define se second
#define vi vector<int>
#define vvi vector<vi>
#define len(x) (int)x.size()
#define pi pair<int,int>
#define vpi vector<pi>
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vi,greater<int>>
#define bits(x) __builtin_popcount(x)
#define fixed(x) cout<<fixed<<setprecision(x);
using namespace std;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," <<   
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.first 
template<class T> ostream& operator<<(ostream &os, vector<T> V) {for(auto v : V) os << v << " ";return os<<"";}
template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}"
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return 
template<class T> ostream& operator<<(ostream &os, multiset<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {os << "{ ";for(auto m:M) os<< 
template<typename T> istream& operator>>(istream& in,vector<T> &a){for(int i=0;i<len(a);i++)in>>a[i];return in;
template<typename T1, typename T2> istream& operator>>(istream& in,pair<T1,T2>&p){in>>p.fi>>p.se;return in;}
template<typename T>
void print(T t){cout<<(t);cout<<'\n';}
template<typename T, typename... Args>
void print(T t, Args... args){cout << (t) <<' ';print(args...);}
inline int mul(int a,int b){return (a*1ll*b)%MOD;}
inline int bpow(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
const int N = 1e6+1;
int spf[N];
void calc(){
    int i;
    for(i=0;i<N;i++)spf[i]=i;
    for(i=4;i<N;i+=2)spf[i]=2;
    for(i=3;i*i<N;i+=2){
        for(int j=i*i;j<N;j+=2*i){
            if(spf[j] == j)spf[j] = i;
        }
    }
}
vpi get(int n){
    vpi a;
    if(n==1){
        a.pb({1,1});
        return a;
    }
    while(n>1){
        int x = spf[n];
        pi p={x,0};
        while(n%x == 0)n/=x,p.se++;
        a.pb(p);
    }
    return a;
}
int f(int n){
    if(n==1)return 1;
    vpi b = get(n);
    if(len(b)==1){
        return b[0].se%3+1;
    }
    int ans = INT_MAX;
    for(int i=0;i<len(b);i++){
        if(b[i].se>=3)ans = min(ans,f(n/pow(b[i].fi,3)));
        // print("HI",n,bpow(b[i].fi,v1),b[i]);
        for(int j=i+1;j<len(b);j++){
            ans = min(ans,f(n/(b[i].fi*b[j].fi)));
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    print(f(n));
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    calc();
    int test;cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
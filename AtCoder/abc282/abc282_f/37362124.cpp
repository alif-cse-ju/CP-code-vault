#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<utility>
#include<tuple>
#include<cstdint>
#include<cstdio>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<cctype>
#include<cassert>
#include<cstddef>
#include<iterator>
#include<string_view>
#include<type_traits>

#ifdef LOCAL
#  include "debug_print.hpp"
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<typename T> using PQ = priority_queue<T,vector<T>>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void yesno(bool flag) {cout << (flag?"Yes":"No") << "\n";}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    int s = (int)v.size();
    for (int i = 0; i < s; i++) os << (i ? " " : "") << v[i];
    return os;
}
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &x : v) is >> x;
    return is;
}
void in() {}
template<typename T, class... U>
void in(T &t, U &...u) {
    cin >> t;
    in(u...);
}
void out() { cout << "\n"; }
template<typename T, class... U, char sep = ' '>
void out(const T &t, const U &...u) {
    cout << t;
    if (sizeof...(u)) cout << sep;
    out(u...);
}
void outr() {}
template<typename T, class... U, char sep = ' '>
void outr(const T &t, const U &...u) {
    cout << t;
    outr(u...);
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n; in(n);
    vector<int> v = {0};
    vector<int> w;
    while(true){
        int x = v.back();
        if(2*x+1 >= n-1) break;
        v.pb(2*x+2);
    }
    rep(i,v.size()){
        w.pb(2*v[i]+1);
    }
    vector<int> l,r;
    FOR(i,1,n+1){
        l.pb(i);
        r.pb(i);
    }
    FOR(i,1,n+1){
        l.pb(i);
        r.pb(i);
    }
    for(int ent : v){
        if(ent == 0) continue;
        FOR(i,1,n+1){
            if(i+ent <= n){
                l.pb(i);
                r.pb(i+ent);
            }
        }
    }
    out(l.size());
    fflush(stdout);
    rep(i,l.size()){
        out(l[i], r[i]);
        fflush(stdout);
    }
    vector<int> sum = {2*n};
    FOR(i,1,v.size()) sum.pb(sum.back() + n-v[i]);
    int q; in(q);
    while(q--){
        int a,b; in(a,b);
        if(a == b){
            out(a,n+a);
            fflush(stdout);
        }
        else if(b == a+1){
            out(a,b);
            fflush(stdout);
        }
        else{
            int idx = 0;
            rep(i,w.size()){
                if(w[i] >= b-a){
                    idx = i;
                    break;
                }
            }
            int x = v[idx];
            int y1 = a, y2 = b-x;
            out(sum[idx-1]+y1, sum[idx-1]+y2);
            fflush(stdout);
        }
    }
    return 0;
}

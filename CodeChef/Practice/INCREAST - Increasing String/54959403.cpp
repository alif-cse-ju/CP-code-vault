#include<bits/stdc++.h>
using namespace std;
template <class T> ostream &operator << (ostream &os, const vector<T> &p) { os << "["; for (auto&it : p) os <<       
template <class S, class T> ostream &operator << (ostream &os, const pair<S, T> &p) { return os << "(" << p.first      
#ifndef ONLINE_JUDGE
#define deb(...) dbs(#__VA_ARGS__,__VA_ARGS__)
template <class T> void dbs(string str, T t) { cerr << str << ":" << t << "\n";}
template<class T, class...S> void dbs(string str, T t, S... s) { int idx = str.find(','); cerr << str.substr(0,           
#else
#define deb(...){}
#endif
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pr(x) {cout << x << '\n'; return;}
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
template<class T> inline T Bit(T x, int i) { return (x >> i) & 1;}
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
clock_t start = clock();
void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<int> last(26, -1);
  for (int i = 0; i < n; i++) {
    last[s[i] - 'a'] = i;
  }
  int dig = 0;
  int mx = 26;
  string ans = s, ans1, ans2;
  for (int i = 0; i < n; i++) {
    while (dig < 26 && i > last[dig]) dig++;
    if (dig == mx) {
      string ans3 = ans2, ans4;
      for (int j = i; j < n; j++) {
        if (s[j] == ('a' + mx)) {
          ans4.push_back(s[j]);
        }
        else {
          ans3.push_back(s[j]);
        }
      }
      ans2 += s.substr(i);
      ans = min(ans, ans1 + min(ans2, ans4 + ans3));
      break;
    } else if (dig > mx) {
      ans = min(ans, ans1 + ans2 + s.substr(i));
      break;
    }
    if (s[i] == ('a' + dig)) {
      ans1.push_back(s[i]);
    } else {
      if (mx == 26) mx = (s[i] - 'a');
      ans2.push_back(s[i]);
    }
    if (i == n - 1) ans = min(ans, ans1 + ans2);
  }
  assert(sz(s) == sz(ans));
  cout << ans << '\n';
}
signed main() {
  ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
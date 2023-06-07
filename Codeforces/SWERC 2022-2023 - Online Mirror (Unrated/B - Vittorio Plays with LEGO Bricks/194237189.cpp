#include <bits/stdc++.h>
using namespace std;
#define int long long
using LL = long long;
// #define TEST_CASES
const int N = 303;
int x[N], n, h;
int dp1[N][N], dp2[N];
int g(int l, int r) {
    if(l >= r) {
        return 0;
    }
    if(~dp1[l][r]) {
        return dp1[l][r];
    }
    int dy = (x[r] - x[l] + 1) / 2 - 1;
    int ans = 1e18;
    for(int i = l; i < r; i++) {
        ans = min(ans, dy + g(l, i) + g(i + 1, r));
    }
    return dp1[l][r] = ans;
int f(int i) {
    if(i > n)
        return 0;
     if(~dp2[i]) {
        return dp2[i];
    }
     int ans = h + f(i + 1);
    for(int j = i + 1; j <= n; j++) {
        int dy = (x[j] - x[i] + 1) / 2 - 1;
        // cout << i << " " << j << " " << dy << endl;
        if(dy < h) {
            ans = min(ans, dy + (h - dy) + g(i, j) + f(j + 1));
        }
    }
     return dp2[i] = ans;
}
 void solve(int tc) {
     memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
     cin >> n >> h;
     for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
     if(h == 0) {
        cout << 0 << endl;
        return;
    }
     cout << f(1) << endl;
        //cout << "Case " << tc << ": ";
}
 int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
     int test = 1, tc = 0;
     #ifdef TEST_CASES
    cin >> test;
    #endif
     while(test--) {
        solve(++tc);
    }
     return 0;
}
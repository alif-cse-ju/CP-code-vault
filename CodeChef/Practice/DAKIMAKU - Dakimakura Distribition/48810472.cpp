#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 228;
long long calc(int i, int j, vector<long long> &sum_c, vector<long long> &sum_t, long long val) {
    long long tmp_val = 0;
    if (sum_c[i + 1] - sum_c[j] == 0)
        return 0;
    if (sum_t[i] - sum_t[j] >= val)
        return inf;
    for (int k = j; k <= i; ++k) {
        long long s1 = sum_c[k + 1] - sum_c[j], s2 = sum_t[i] - sum_t[k];
        tmp_val = max(tmp_val, (s1 + val - s2 - 1) / (val - s2));
    }
    return tmp_val;
}
bool check(int n, int x, vector<int> &c, vector<int> &t, long long val) {
    vector<long long> dp(n + 1, inf);
    vector<long long> sum_c(n + 1);
    vector<long long> sum_t(n);
    for (int i = 0; i < n; ++i) {
        sum_c[i + 1] = c[i] + sum_c[i];
        if (i != n - 1)
            sum_t[i + 1] = t[i] + sum_t[i];
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1] = min(dp[i + 1], dp[j] + calc(i, j, sum_c, sum_t, val));
        }
    }
    return dp.back() <= x;
}
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n), t(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> t[i];
    long long l = -1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(n, x, c, t, mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
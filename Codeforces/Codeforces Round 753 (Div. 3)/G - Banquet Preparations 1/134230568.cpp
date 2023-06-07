#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
int t, n;
ll m, a[N], b[N], up[N], ans[N];
int main() {
  cin >> t;
while (t--) {
    scanf("%d %lld", &n, &m);
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld", a + i, b + i);
      b[i] = m - b[i], tot += a[i] + b[i];
      ll l = max(0LL, b[i]), r = min(m, a[i]);
      tot -= 2 * l, ans[i] = l, up[i] = r - l;
    }
    for (int i = 1; i <= n; ++i) if (tot > 0) {
      ll out = min(up[i], tot / 2);
      tot -= 2 * out, ans[i] += out;
    }
    printf("%lld\n", abs(tot));
    for (int i = 1; i <= n; ++i) printf("%lld %lld\n", ans[i], m - ans[i]);
}
return 0;
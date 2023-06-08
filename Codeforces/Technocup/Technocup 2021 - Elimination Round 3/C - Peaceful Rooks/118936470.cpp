#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> me(n, n + 1);
        int ret = 0;
        while (k--) {
            int x, y;
            cin >> x >> y;
            if (x != y) {
                me[x - 1] = y - 1;
                ++ret;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (me[i] == n + 1)
                continue;
            int t = me[i];
            me[i] = n + 1;
            while (t != n + 1 && t != i) {
                int tt = t;
                t = me[t];
                me[tt] = n + 1;
            }
            if (t == i)
                ++ret;
        }
         cout << ret << '\n';
    }
     return 0;
}
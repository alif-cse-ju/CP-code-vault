#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 228;
template<class T, class Fun = function<T(const T &, const T &)>>
struct SegTree {
    Fun f;
    vector<T> t;
    int n;
    SegTree(int sz, const Fun &g, T default_value = T()) : f(g) {
        n = 1;
        while (n < sz) n <<= 1;
        t.resize(n * 2, default_value);
    }
    SegTree(vector<T> &a, const Fun &g, T default_value = T()) : SegTree(a.size(), g, default_value) {
        for (int i = 0; i < n; ++i) t[i + n] = a[i];
        for (int i = n - 1; i >= 1; --i) t[i] = f(t[i << 1], t[i << 1 | 1]);
    }
    void upd(int i, T x) {
        i += n;
        t[i] = f(t[i], x);
        for (i >>= 1; i > 1; i >>= 1) t[i] = f(t[i << 1], t[i << 1 | 1]);
    }
    T get(int l, int r) {
        T resL = t[0], resR = t[0];
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = f(resL, t[l++]);
            if (r & 1) resR = f(t[--r], resR);
        }
        return f(resL, resR);
    }
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> posts(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        posts[r].push_back({l, i});
    }
    SegTree<int> ind(n + 1, [](int x, int y) { return max(x, y); }, -1);
    SegTree<int> dp(n + 1, [](int x, int y) { return min(x, y); }, inf);
    vector<int> answer(q);
    for (int i = 0; i < n; i++) {
        {
            int limit = n + 1;
            while (true) {
                int j = ind.get(a[i], limit);
                if (j == -1)
                    break;
                dp.upd(j, abs(a[j] - a[i]));
                limit = a[i] + (a[j] - a[i] + 1) / 2;
            }
        }
        {
            int limit = 0;
            while (true) {
                int j = ind.get(limit, a[i]);
                if (j == -1)
                    break;
                dp.upd(j, abs(a[j] - a[i]));
                limit = a[i] - (a[i] - a[j] + 1) / 2 + 1;
            }
        }
        ind.upd(a[i], i);
        for (pair<int, int> j: posts[i]) {
            answer[j.second] = dp.get(j.first, i);
        }
    }
    for (int i: answer) {
        cout << i << "\n";
    }
     return 0;
}
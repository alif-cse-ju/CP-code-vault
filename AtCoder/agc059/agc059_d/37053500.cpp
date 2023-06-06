#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    n += k - 1;
    vector<int> a(n);
    for (int i = k - 1; i < n; i++) {
        cin >> a[i];
        a[i] = k - a[i];
    }
    for (int i = k - 2; i >= 0; i--) {
        a[i] = max(a[i + 1] - 1, 0);
    }
    vector<int> pos(n, -1), hl, hr;
    for (int i = 1; i < n; i++) {
        int cur = a[i] - a[i - 1];
        if (cur < -1 || cur > 1) {
            cout << "NO\n";
            return;
        }
        if (cur >= 0) {
            hl.push_back(i);
        }
        if (cur <= 0) {
            hr.push_back(i);
        }
    }
    for (int i = 0; i < a[n - 1]; i++) {
        hr.push_back(n + i);
    }
    for (int i = 0; i < hl.size(); i++) {
        if (hl[i] != hr[i]) {
            pos[hl[i]] = hr[i] - k;
            if (pos[hl[i]] >= hl[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i] == -1) {
            a[i] = ++cnt;
        } else {
            a[i] = a[pos[i]];
        }
    }
    cout << "YES\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
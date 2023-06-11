#include <bits/stdc++.h>
using namespace std;
void run_case() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int mx = 0;
    for (auto &x : mp)
        mx = max(mx, x.second);
    if (n <= 1 || mx <= n / 3)
        cout << "YES\n";
    else
        cout << "NO\n";
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        int T = 1; 
    cin >> T; 
    while (T--) {
        run_case();        
    }
        return 0;
}
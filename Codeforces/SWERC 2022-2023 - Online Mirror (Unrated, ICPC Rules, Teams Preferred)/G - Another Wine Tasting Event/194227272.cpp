#include <bits/stdc++.h>
using namespace std;

using LL = long long;
// #define TEST_CASES

void solve(int tc) {
    int n; cin >> n;
    string str; cin >> str;

    vector <int> cnt(2 * n + 1, 0);

    for(int i = 1; i <= str.size(); i++) {
        cnt[i] = cnt[i - 1] + (str[i - 1] == 'W');
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans = max(ans, cnt[i + n - 1] - cnt[i - 1]);
    }

    cout << ans << endl;
    
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

using LL = long long;
// #define TEST_CASES

void solve(int tc) {

    int n; cin >> n;

    string str; cin >> str;

    int pos = 0, neg = 0;

    for(auto ch: str) {
        if(ch == '+') pos++;
        else          neg++;
    }

    int q; cin >> q;

    for(int i = 1; i <= q; i++) {
        int a, b; cin >> a >> b;

        int mn = min(a, b);

        a -= mn;
        b -= mn;

        int current_score = (pos - neg) * mn;

        if(current_score == 0) {
            cout << "YES" << endl;
            continue;
        }

        int delta = abs(a - b);

        if(delta == 0) {
            cout << "NO" << endl;
            continue;
        }

        current_score *= -1;

        if(current_score % delta == 0) {
            int val = current_score / delta;
            if(val >= -neg and val <= pos) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
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
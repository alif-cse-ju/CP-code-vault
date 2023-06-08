#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> x(n+m);
    for (int& i : x) cin >> i;
    vector<int> taxi, rider;
    for (int i = 0; i < n+m; i++) {
        int k; cin >> k;
        if (k) taxi.push_back(x[i]);
        else rider.push_back(x[i]);
    }
    vector<int> ans(m);
    //cerr << rider.size() << nl;
    for (int i : rider) {
        auto it = lower_bound(taxi.begin(), taxi.end(), i);
        int best = INF, besti = -1;
        if (it != taxi.end()) {
            best = *it - i;
            besti = it - taxi.begin();
        }
        if (it != taxi.begin()) {
            it--;
            if (i - *it <= best) {
                best = i - *it;
                besti = it - taxi.begin();
            }
        }
        ans[besti]++;
    }
    for (int i : ans) cout << i << " ";
    cout << nl;
    return 0;
}
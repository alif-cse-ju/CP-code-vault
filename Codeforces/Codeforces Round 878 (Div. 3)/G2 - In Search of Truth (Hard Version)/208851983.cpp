#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int MAXN = 1e6 + 7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int pos[MAXN];
 
const int K = 400;
const int T = 300;
 
int get() {
    return rng() % MAXN;
}
 
int32_t main() {
    int num;
    cin >> num;
    int start = num;
    int cur_delta = 0;
    int N0 = num;
    for (int i = 0; i < K; ++i) {
        int delta = get();
        cout << '+' << " " << delta << endl;
        cur_delta += delta;
        cin >> num;
        N0 = max(N0, num);
    }
    cout << '-' << " " << cur_delta << endl;
    cin >> num;
    cout << '+' << " " << N0 - 1 << endl;
    cur_delta = N0 - 1;
    cin >> num;
    pos[num] = N0;
    for (int i = 0; i < T; ++i) {
        ++cur_delta;
        cout << '+' << " " << 1 << endl;
        cin >> num;
        pos[num] = N0 + i + 1;
        if (num == start) {
            cout << '!' << " " << N0 + i << endl;
            return 0;
        }
    }
    cout << '-' << " " << cur_delta << endl;
    cin >> num;
    int ans = 0;
    while (true) {
        cout << '-' << " " << T << endl;
        ans += T;
        cin >> num;
        if (pos[num]) {
            cout << '!' << " " << ans + pos[num] - 1 << endl;
            return 0;
        }
    }
    return 0;
}
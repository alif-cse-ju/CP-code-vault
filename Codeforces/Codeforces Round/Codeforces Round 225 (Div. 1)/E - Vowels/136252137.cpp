#include <bits/stdc++.h>
using namespace std;
const int N = 24, M = (1 << N);
int dp[M];
int32_t main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s; int mask = 0;
        mask |= (1 << (s[0] - 'a'));
        mask |= (1 << (s[1] - 'a'));
        mask |= (1 << (s[2] - 'a'));
        dp[mask]++;
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if((j >> i) & 1)
                dp[j] += dp[j ^ (1 << i)];
    int ans = 0;
    for(int i = 0; i < M; i++) {
        ans ^= (n - dp[(M - 1) ^ i]) * (n - dp[(M - 1) ^ i]);
    }
    cout << ans << endl;
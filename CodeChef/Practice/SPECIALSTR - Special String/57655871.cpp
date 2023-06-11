#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define sz(w) (int)(w.size())
using pii = pair<int, int>;
const long long INF = 1e18;
const int N = 1e6 + 5; 
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s = '#' + s;
    int m; cin >> m;
    vector<int> occ(26, n + 1), par(n + 1);
    for(int i = n; i >= 1; i--)
    {
        int nxt = (s[i] - 'a' + 1) % 26;
        par[i] = occ[nxt];
        occ[s[i] - 'a'] = i; 
    }
    int lg = log2(m) + 1;
    vector<vector<int>> dp(lg + 1, vector<int>(n + 2, n + 1));
    for(int i = n; i >= 1; i--)
    {
        dp[0][i] = par[i];
        for(int j = 1; j <= lg; j++)
        {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }
    int ans = INF;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] != 'a')
            continue;
        int u = i, m_copy = m - 1;
        for(int j = lg; j >= 0; j--)
        {
            if((1 << j) <= m_copy)
                u = dp[j][u], m_copy -= 1 << j;
        }
        if(u != n + 1)
            ans = min(ans, u - i + 1 - m);
    }
    if(ans == INF)
        ans = -1;
    cout << ans << endl;
}
int32_t main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
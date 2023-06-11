#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define sz(w) (int)(w.size())
const int mod = 998244353;
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int ans = 1;
    for(int i = 0; i < k; i++)
    {
        vector<int> bit(n);
        for(int j = 0; j < n; j++)
            bit[j] = (a[j] >> i) & 1;
        int cnt0 = count(bit.begin(), bit.end(), 0);
        int res = cnt0 + 1;
        for(int j = 0; j < n; j++)
        {
            if(bit[j] == 0)
                cnt0--;
            else
                res += cnt0 + 1;
        }
        ans = ans * (res % mod) % mod;
    }    
    cout << ans << endl;
}
int32_t main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int T; cin >> T;
    while(T--)
        solve();
    return 0;
}
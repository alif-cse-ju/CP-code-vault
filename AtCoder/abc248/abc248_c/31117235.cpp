#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int mod = 998244353;
inline void inc(int &x, int y) { x = (x + y) % mod; }
int n, m, k;
int f[N][N * N];
int main()
{
	cin >> n >> m >> k;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= k; j++)
	for (int p = 1; p <= min(j, m); p++)
	inc(f[i][j], f[i - 1][j - p]);
	int ans = 0;
	for (int i = 0; i <= k; i++) inc(ans, f[n][i]);
	cout << ans << "\n";
	return 0;
}
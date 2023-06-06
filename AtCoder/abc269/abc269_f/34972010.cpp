#include<bits/stdc++.h>
#define ll long long
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define int ll
const int MOD = 998244353;
int M;
int esum(int n){
	int x = n / 2;
	return (x * (x + 1))  % MOD;
}
int osum(int n){
	int x = (n + 1) / 2;
	return (x * (x)) % MOD;
}
int query(int x,int y){
	if(x < 1) return 0;
	if(y < 1) return 0; 
	int ret = 0;
	ret = osum(y) * ((x + 1) / 2) % MOD;
	ret = (ret + (esum(y) * (x / 2))) % MOD;
	int tmp = esum(x - 1) * ((y + 1) / 2) % MOD;
	tmp = (tmp * M) % MOD;
	ret = (ret + tmp) % MOD;
	tmp = osum(x - 1) * (y / 2) % MOD;
	tmp = tmp * M % MOD;
	ret = (ret + tmp) % MOD;
	return ret;
}
int query(int a,int b,int c,int d){
	return (((query(b , d) - query(b,c - 1) - query(a - 1, d) + query(a  - 1, c - 1)) % MOD) + MOD) % MOD;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	M = m;
	int q;
	cin >> q;
	while(q--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << query(a, b, c, d) << '\n';
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--) solve();
}
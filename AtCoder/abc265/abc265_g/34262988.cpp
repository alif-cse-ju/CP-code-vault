#include <bits/stdc++.h>
#define ts(x) cout << #x << '=' << x << '\n';
using namespace std;
template <typename F> inline void read(F &n) {
	F w = 1; n = 0;
	char ch = getchar();
	while (!isdigit(ch) && ch != EOF) { if(ch == '-') w = -1; ch = getchar(); } 
	while (isdigit(ch) && ch != EOF) { n = (n << 1) + (n << 3) + (ch & 15); ch = getchar(); }
	n *= w;
}
template <typename T, typename ...L> inline void read(T &n,L &...l) { read(n); read(l...); }
template <typename T> inline void write(T n) {
	if (n < 0) { putchar('-'); n = -n; }
	if (n > 9) write(n / 10);  putchar('0' + n % 10);
}
template <typename T> inline void ckmax(T &x, T y) { x = x > y ? x : y; }
template <typename T> inline void ckmin(T &x, T y) { x = x < y ? x : y; }
typedef long long ll;
typedef unsigned long long ull;
#define int ll

const int N = 2e5 + 5;
int n, Q, A[N];
#define lc (k << 1)
#define rc ((k << 1) | 1)
struct node{
	int cnt[3];
	ll mat[3][3], res;
	node() { clr(); }
	void clr() {
		for (int i = 0; i < 3; ++i) {
			cnt[i] = 0;
			for (int j = 0; j < 3; ++j) {
				mat[i][j] = 0;
			}
		}
		res = 0;
	}
	friend node operator+(node x, node y) {
		node z; z.clr();
		for (int i = 0; i < 3; ++i) z.cnt[i] = x.cnt[i] + y.cnt[i];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				z.mat[i][j] = 1ll * x.cnt[i] * y.cnt[j] + x.mat[i][j] + y.mat[i][j];
				if (i > j) z.res += z.mat[i][j];
			}
		}
		return z;
	}
}t[N << 2], o;
int lazy[N << 2][3];
void clrlazy(int k) { lazy[k][0] = 0; lazy[k][1] = 1; lazy[k][2] = 2; }
void pushup(int k) {
	t[k] = t[lc] + t[rc];
}
void upd(int k, int v[]) {
	node tmp;
	for (int i = 0; i < 3; ++i) {
		lazy[k][i] = v[lazy[k][i]];
		tmp.cnt[v[i]] += t[k].cnt[i];
		for (int j = 0; j < 3; ++j) {
			tmp.mat[v[i]][v[j]] += t[k].mat[i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < i; ++j) {
			tmp.res += tmp.mat[i][j];
		}
	}
	t[k] = tmp;
}
void pushdown(int k) {
	if (lazy[k][0] != 0 || lazy[k][1] != 1 || lazy[k][2] != 2) {
		upd(lc, lazy[k]);
		upd(rc, lazy[k]);
		clrlazy(k);
	}
}
void doBuild(int k, int l, int r) {
	clrlazy(k);
	if (l == r) {
		t[k].cnt[A[l]] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	doBuild(lc, l, mid);
	doBuild(rc, mid + 1, r);
	pushup(k);
}
void doUpdate(int k, int l, int r, int L, int R, int v[]) {
	pushdown(k);
	if (l > R || r < L) return;
	if (l >= L && r <= R) {
		upd(k, v);
		return;
	}
	int mid = (l + r) >> 1;
	doUpdate(lc, l, mid, L, R, v);
	doUpdate(rc, mid + 1, r, L, R, v);
	pushup(k);
}
node doQuery(int k, int l, int r, int L, int R) {
	pushdown(k);
	if (l > R || r < L) return o;
	if (l >= L && r <= R) return t[k];
	int mid = (l + r) >> 1;
//	if (R <= mid) return doQuery(lc, l, mid, L, R);
//	if (L > mid) return doQuery(rc, mid + 1, r, L, R);
	return doQuery(lc, l, mid, L, R) + doQuery(rc, mid + 1, r, L, R);
}
signed main() {
#ifdef LOCAL_JUDGE
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);
#endif
	read(n, Q);
	for (int i = 1; i <= n; ++i) {
		read(A[i]);
	}
	doBuild(1, 1, n);
	int op, L, R, v[3];
	for (; Q; --Q) {
		read(op, L, R);
		if (op == 1) printf("%lld\n", doQuery(1, 1, n, L, R).res);
		else {
			read(v[0], v[1], v[2]);
			doUpdate(1, 1, n, L, R, v);
		}
	}
	return 0;
}
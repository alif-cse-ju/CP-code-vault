#include <cstdio>
#include <algorithm>
#define N_MAX 20
#define M_MAX 100000
#define L_MAX (1 << N_MAX)
#define lld "%lld"
typedef long long lnt;
typedef char cnt;
typedef void vnt;
int n, m, l, i, j, x[M_MAX];
cnt tmp[M_MAX + 1];
lnt a[L_MAX + 1], b[L_MAX + 1], ans;
inline vnt fwt(lnt a[])
{
	int i, j, k; lnt u, v;
	for (k = 1; k < l; k <<= 1)
		for (i = 0; i < l; i += k << 1)
			for (j = 0; j < k; ++j)
				u = a[i + j], v = a[i + j + k], a[i + j] = u + v, a[i + j + k] = u - v;
}
int main()
{
	scanf("%d %d", &n, &m);
	l = 1 << n;
	for (i = 0; i < n; ++i)
	{
		scanf("\n%s", tmp);
		for (j = 0; j < m; ++j)
			x[j] |= int(tmp[j] - '0') << i;
	}
	for (i = 0; i < m; ++i)
		++a[x[i]];
	for (i = 0; i < l; ++i)
		b[i] = std::min(__builtin_popcount(i), n - __builtin_popcount(i));
	fwt(a), fwt(b);
	for (i = 0; i < l; ++i)
		a[i] *= b[i];
	fwt(a);
	ans = lnt(n * m) << n;
	for (i = 0; i < l; ++i)
		ans = std::min(ans, a[i]);
	printf(lld "\n", ans >> n);
	return 0;
}

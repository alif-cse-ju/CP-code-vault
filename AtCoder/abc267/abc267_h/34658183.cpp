#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace std;

#define re register
#define Re register
#define i64 long long
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout);

#define defrog(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); de_frog(_it, args);}
inline void de_frog(istream_iterator<string> it) {}
template<typename T, typename... Args>
inline void de_frog(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << '\n', de_frog(++it, args...);}

const int N = 1e6 + 5, inf = 0x3f3f3f3f, P = 998244353;

using mint = atcoder::modint998244353;

inline int ksm(mint a, int b)
{
    mint res = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        a *= a;
        b >>= 1;
    }
    return res.val();
}

const int g = 3, ig = ksm(3, P - 2);
int rev[N << 2];

inline void NTT(mint *A, int siz, bool flag)
{
    for (re int i = 0; i < siz; ++i) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (re int len = 1; len < siz; len <<= 1)
    {
        const int rlen = len << 1, wn = ksm(flag ? ig : g, (P - 1) / rlen);
        for (re int i = 0; i < siz; i += rlen)
        {
            mint w = 1;
            for (re int j = 0; j < len; ++j, w *= wn)
            {
                const mint x = A[i + j], y = A[i + j + len] * w;
                A[i + j] = x + y, A[i + j + len] = x - y;
            }
        }
            
    }
    if (flag)
    {
        const int inv = ksm(siz, P - 2);
        for (re int i = 0; i < siz; ++i) A[i] *= inv;
    }
}

mint fac[N], inv[N];
inline mint C(int n, int m) {return fac[n] * inv[m] * inv[n - m];}

mint dp[2][N << 2], a[2][N << 2], b[2][N << 2];

inline void init(int n)
{
    fac[0] = 1;
    for (re int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
    inv[n] = ksm(fac[n], P - 2);
    for (re int i = n - 1; ~i; --i) inv[i] = inv[i + 1] * (i + 1);    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    static int cnt[11];
    for (re int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        ++cnt[x];
    }

    init(n);

    dp[0][0] = 1;
    int len = 0, siz = 1, L = 0;

    for (re int i = 1; i <= 10; ++i)
    {
        if (!cnt[i]) continue;
        for (re int j = 0; j <= cnt[i]; ++j) a[j & 1][j * i] = C(cnt[i], j);

        len += cnt[i] * i;
        
        while (siz <= len) siz <<= 1, ++L;
        for (re int j = 0; j < siz; ++j) rev[j] = (rev[j >> 1] >> 1) | ((j & 1) << L - 1);

        NTT(dp[0], siz, 0), NTT(dp[1], siz, 0);
        NTT(a[0], siz, 0), NTT(a[1], siz, 0);
        for (re int j = 0; j < siz; ++j)
        {
            b[0][j] = a[0][j] * dp[0][j] + a[1][j] * dp[1][j];
            b[1][j] = a[0][j] * dp[1][j] + a[1][j] * dp[0][j];
            a[0][j] = a[1][j] = 0;
        }

        NTT(b[0], siz, 1), NTT(b[1], siz, 1);

        for (re int j = 0; j <= len; ++j)
            dp[0][j] = b[0][j], dp[1][j] = b[1][j];
        for (Re int j = len + 1; j < siz; ++j)
            dp[0][j] = dp[1][j] = 0;
    }

    cout << dp[1][m].val() << '\n';
    
    return 0;
}
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int st[18][(int)1e5 + 10], plog2[(int)1e5 + 10];
int gcd(int a, int b)
    if(!b) return a;
    return gcd(b, a % b);
void init(int n)
    for(int i = 1; i< 17; i++)
    {
        for(int j = 1; j + (1 << i) - 1 <= n; j++) st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
struct Node
    int l, Rl, Rr;
vector <LL> v[(int)1e6 + 5], exis;
vector <Node> s[(int)1e6 + 5];
int GCD(int l, int r)
    int k = plog2[r - l + 1];
    return gcd(st[k][l], st[k][r - (1 << k) + 1]);
int cmp1(const Node &a, const Node &b)
    return a.l < b.l;
}
 int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("gcdrng.in", "r", stdin);
    for(int i = 1; i <= 1e5 + 5; i++) plog2[i] = floor(log2(i) + 1e-6);
    int T; cin >> T;
    while(T--)
    {
        int n, q; cin >> n >> q;
        for(int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            st[0][i]=x;
        }
        init(n), exis.clear();
        for(int l = 1; l <= n; l++)
        {
            int r = l, ini = st[0][l];
            while(r <= n)
            {
                ini = GCD(l, r);
                int L=r, R=n;
                while(L < R)
                {
                    int mid = (L + R +1) >> 1;
                    if(GCD(l, mid) == ini) L = mid;
                    else R = mid - 1;
                }
                s[ini].emplace_back(Node{l, r, L});
                exis. emplace_back(ini);
                r = L + 1;
            }
        }
        sort(exis.begin(), exis.end());
        exis. erase(unique(exis.begin(), exis.end()), exis.end());
        for(auto g : exis)
        {
            LL up = 0;
            sort(s[g].begin(), s[g].end(), cmp1);
            v[g].emplace_back(0);
            for(auto i : s[g])v[g].emplace_back(up + i.Rr - i.Rl + 1), up = v[g].back();
        }
        for(int i = 1; i <= q; i++)
        {
            int ql, qr, d; cin >> ql >> qr >> d;
            LL ans = 0;
            int siz = (int)s[d].size();
            if(!siz)
            {
                cout << 0 << '\n';
                continue;
            }
            int L = 0, R= siz - 1;
            while(L < R)
            {
                int mid = (L +R) >> 1;
                if(s[d][mid].l >= ql) R = mid;
                else L = mid + 1;
            }
            int tl = L;
            if(s[d][tl].l < ql || s[d][tl].Rl > qr)
            {
                cout << 0 << '\n';
                continue;
            }
            R = siz - 1;
            while(L < R)
            {
                int mid = (L + R + 1) >> 1;
                if(s[d][mid].Rl <= qr) L = mid;
                else R = mid - 1;
            }
            int tr = L;
            R = tr, L = tl;
            while(L < R)
            {
                int mid = (L + R + 1) >> 1;
                if(s[d][mid].Rr <= qr) L = mid;
                else R = mid - 1;
            }
            if(s[d][L].Rr > qr) L--;
            ans += v[d][tr + 1] - v[d][tl];
            ans -= (LL)(s[d][tr].Rr - qr) * (tr - L);
            cout << ans << '\n';
        }
        for(auto g : exis) s[g].clear(), v[g].clear();
    }
    return 0;
}
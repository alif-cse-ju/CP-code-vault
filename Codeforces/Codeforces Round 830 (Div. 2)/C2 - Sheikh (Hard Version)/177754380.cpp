#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, qq;
int a[N];

ll ps[N];
int px[N];

ll qry(int l, int r)
{
    if (l > r)
        return 0;
    return (ps[r] - ps[l - 1] - (px[r] ^ px[l - 1]));
}

int ul[N], ur[N];
void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        ps[i] = ps[i - 1] + a[i];
        px[i] = (px[i - 1] ^ a[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        ul[i] = ul[i - 1];
        if (a[i])
            ul[i] = i;
    }
    ur[n + 1] = n + 1;
    for (int i = n; i >= 1; --i)
    {
        ur[i] = ur[i + 1];
        if (a[i])
            ur[i] = i;
    }

    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        if (qry(l, r) == 0)
        {
            cout << l << ' ' << l << "\n";
            continue;
        }

        int ansl = l, ansr = r;

        int i = l;
        while (1)
        {
            if (qry(i, r) != qry(l, r))
                break;
            int j = r;
            while (1)
            {
                if (qry(i, j) != qry(l, r))
                    break;
                if (j - i < ansr - ansl)
                {
                    ansl = i;
                    ansr = j;
                }
                j = ul[j - 1];
            }
            i = ur[i + 1];
        }

        cout << ansl << ' ' << ansr << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}

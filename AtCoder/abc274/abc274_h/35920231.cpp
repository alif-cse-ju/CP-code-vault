#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;

using ull = unsigned long long;
const int M = 256;
ull np_memo[M][M];

ull nim_product(ull a, ull b, int p=64, bool pr=false){
    if(min(a, b) <= 1) return a * b;
    while(max(a, b) < (1uLL << (p >> 1))) p >>= 1;

    if (!pr && p <= 8){
        return np_memo[a][b];
    }

    p >>= 1;
    ull a1 = a >> p;
    ull a2 = a & ((1uLL << p) - 1);
    ull b1 = b >> p;
    ull b2 = b & ((1uLL << p) - 1);

    ull c = nim_product(a1, b1, p, pr);
    ull d = nim_product(a2, b2, p, pr);
    ull e = nim_product(a1 ^ a2, b1 ^ b2, p, pr);
    return nim_product(c, 1uLL << (p - 1), p, pr) ^ d ^ ((d ^ e) << p);
}

void init(){
    for(int i = 0; i < M; i++) for(int j = 0; j < M; j++){
        np_memo[i][j] = nim_product(i, j, 64, true);
    }
}

class RH_nim{
    public:
    int n;
    vector<ull> pw, hs;
    ull basis;
    RH_nim(vector<ull> &A){
        n = A.size();
        pw.resize(n + 1);
        hs.resize(n + 1);
        pw[0] = 1;
        hs[0] = 0;
        mt19937_64 rnd(time(NULL));
        basis = rnd();
        for(int i = 1; i <= n; i++){
            pw[i] = nim_product(pw[i - 1], basis);
            hs[i] = nim_product(hs[i - 1], basis) ^ A[i - 1];
        }
    }

    ull get(int l, int r){
        return nim_product(hs[l], pw[r - l]) ^ hs[r];
    }
};

void solve(){
    init();
    int n, Q;
    cin >> n >> Q;
    vector<ull> A(n);
    for(auto &a: A) cin >> a;

    RH_nim rh(A);
    int a, b, c, d, e, f, l, r, mid;
    ull r1, r2, x0, x1;
    while(Q--){
        cin >> a >> b >> c >> d >> e >> f;
        a--; c--; e--;
        r = min(b - a, f - e);
        r1 = rh.get(a, a + r) ^ rh.get(c, c + r);
        r2 = rh.get(e, e + r);
        if(r1 == r2){
            if(f - e == r) cout << "No\n";
            else cout << "Yes\n";
            continue;
        }
        l = 0;
        while(r - l > 1){
            mid = (l + r) / 2;
            r1 = rh.get(a, a + mid) ^ rh.get(c, c + mid);
            r2 = rh.get(e, e + mid);
            if(r1 == r2) l = mid;
            else r = mid;
        }
        x0 = A[a + l] ^ A[c + l];
        x1 = A[e + l];
        if(x0 < x1) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
}
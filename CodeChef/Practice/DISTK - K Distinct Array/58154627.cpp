#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define LL long long
LL seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
#define rand(l, r) uniform_int_distribution<LL>(l, r)(rng)
clock_t start = clock();
#define getchar getchar_unlocked
namespace IO {
long long readInt(char endd) {
    long long ret = 0;
    char c = getchar();
    while (c != endd) {
        ret = (ret * 10) + c - '0';
        c = getchar();
    }
    return ret;
}
long long readInt(long long L, long long R, char endd) {
    long long ret = readInt(endd);
    assert(ret >= L && ret <= R);
    return ret;
}
long long readIntSp(long long L, long long R) {
    return readInt(L, R, ' ');
}
long long readIntLn(long long L, long long R) {
    return readInt(L, R, '\n');
}
string readString(int l, int r) {
    string ret = "";
    char c = getchar();
    while (c == '0' || c == '?' || c == '1') {
        ret += c;
        c = getchar();
    }
    assert((int)ret.size() >= l && (int)ret.size() <= r);
    return ret;
}
}
using namespace IO;
const int TMAX = 1'00'000;
const int N = (int)1e5;
const LL K = (N * 1LL * (N + 1)) / 2;
LL sum_n = 0;
void solve() {
    int n = readIntSp(1, N);
    sum_n += n;
    LL k = readIntLn(n, (n * 1LL * (n + 1)) / 2);
    k -= n;
    int i = 0, nxt = 1, cur = 0;
    while (k >= cur) {
        cout << cur + 1 << " ";
        ++i;
        k -= cur;
        ++cur;
    }
    while (i < n) {
        cout << cur - k << " ";
        ++i;
    }
    cout << '\n';
}
int main() {
    int T = readIntLn(1, TMAX);
    while (T--) {
        solve();
    } 
    assert(sum_n <= 3 * N);
    assert(getchar() == EOF);
    cerr << fixed << setprecision(10);
    cerr << (clock() - start) / ((long double)CLOCKS_PER_SEC) << " secs\n";
    return 0;
}
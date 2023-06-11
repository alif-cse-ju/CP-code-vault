#include "bits/stdc++.h"
using namespace std;
 #define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
#define uwu ios::sync_with_stdio(false);cin.tie(NULL);
 const int INF = 1e9 + 7;
const long long INF2 = 1e17;
int main(void) {
    uwu
        auto factor = [] (int x) {
        int res = 0;
        for(int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                res++;
                while(x % i == 0) x /= i;
            }
        }
        res += (x != 1);
        return res;
    };
        int a, b, sum; cin >> a >> b >> sum;
    vector <int> v;
    for(int i = a; i <= b; i++) {
        v.push_back(factor(i));
    }
        vector <int> dp(sum + 1);
    dp[0] = 1;
    for(int x: v) {
        for(int j = (int)dp.size() - 1; j >= 0; j--) {
            if (j + x < (int)dp.size()) {
                dp[j + x] += dp[j];
                if (dp[j + x] >= INF) dp[j + x] -= INF;
            }
        }
    }
    cout << dp.back() << '\n';
}
#include <iostream>
#include <vector>

#include "atcoder/modint.hpp"
using namespace std;
using mint = atcoder::modint998244353;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (auto& x : A) cin >> x;
  for (auto& x : B) cin >> x;
  int MAX = 3000;
  vector dp(vector(N + 1, vector(MAX + 1, mint{0})));
  dp[0][0] = 1;
  rep(i, N + 1) {
    rep(j, MAX) dp[i][j + 1] += dp[i][j];
    if (i != N) {
      for (int j = A[i]; j <= B[i]; j++) dp[i + 1][j] += dp[i][j];
    }
  }
  cout << dp[N][MAX].val() << "\n";
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 808;

int a[sz][sz], dp[sz][sz];

int main() {
   int n, k;
   cin >> n >> k;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         scanf("%d", &a[i][j]);
      }
   }

   int need = (k * k + 1) / 2, lo = 0, hi = 1e9;
   while(lo < hi) {
      int md = lo + hi >> 1;
      bool yes = 0;
      for(int i=1; i<=n; i++) {
         for(int j=1; j<=n; j++) {
            dp[i][j] = (a[i][j] <= md) + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(i < k or j < k) continue;
            int now = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
            if(now >= need) yes = 1;
         }
      }
      if(yes) hi = md;
      else lo = md + 1;
   }
   cout << lo;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int n, k, a[sz], b[sz], dp[sz][69];

int fnc(int i, int j) {
   if(!i) return 0;
   int &w = dp[i][j];
   if(w >= 0) return w;
   w = 1 + fnc(i - 1, j);
   if(j) w = min(w, fnc(b[i], j - 1));
   return w;
}

int main() {
   cin >> n >> k;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   sort(a+1, a+n+1);
   for(int i=1; i<=n; i++) {
      b[i] = upper_bound(a+1, a+n+1, a[i] / 2) - a - 1;
   }

   memset(dp, -1, sizeof(dp));
   for(int j=0; ; j++) {
      int ans = fnc(n, j);
      if(ans <= k) {
         cout << j << " " << ans;
         break;
      }
   }
}

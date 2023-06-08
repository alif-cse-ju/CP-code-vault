// Author: Yen-Jen Wang
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
int n;
int pre = INF;
  scanf("%d", &n);
for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    if (y <= pre) pre = y;
    else if (x <= pre) pre = x;
    else {
      puts("NO");
      return 0;
    }
}
  puts("YES");
return 0;
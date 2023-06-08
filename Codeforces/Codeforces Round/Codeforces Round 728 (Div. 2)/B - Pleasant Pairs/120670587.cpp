#include <iostream>
#include <cstdio>
#include <algorithm>
const int nn = 1e5 + 5;
typedef long long ll;
int n, t;
struct node {
 ll val; int id;
 int operator< (const node &rhs)const {
  return val < rhs.val;
 }
 a[nn];
int main() {
 scanf("%d", &t);
 while (t--) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
   scanf("%lld", &a[i].val);
   a[i].id = i;
  }
  int ans = 0;
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
   for (int j = i + 1; j <= n; j++) {
    if (a[i].val * a[j].val >= n * 2)
     break;
    ans += a[i].val * a[j].val == a[i].id + a[j].id;
   }
  }
  printf("%d\n", ans);
 }
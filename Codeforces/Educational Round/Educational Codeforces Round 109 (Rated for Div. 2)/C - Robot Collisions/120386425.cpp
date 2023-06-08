#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
struct bot{
 int x, d;
int main() {
 int t;
 cin >> t;
 forn(_, t){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<bot> a(n);
  forn(i, n) scanf("%d", &a[i].x);
  forn(i, n){
   char c;
   scanf(" %c", &c);
   a[i].d = c == 'L' ? -1 : 1;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&a](int x, int y){
   return a[x].x < a[y].x;
  });
  vector<int> ans(n, -1);
  vector<vector<int>> par(2);
  for (int i : ord){
   int p = a[i].x % 2;
   if (a[i].d == -1){
    if (par[p].empty())
     par[p].push_back(i);
    else{
     int j = par[p].back();
     par[p].pop_back();
     ans[i] = ans[j] = (a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
    }
   }
   else{
    par[p].push_back(i);
   }
  }
  forn(p, 2){
   while (int(par[p].size()) > 1){
    int i = par[p].back();
    par[p].pop_back();
    int j = par[p].back();
    par[p].pop_back();
    ans[i] = ans[j] = (2 * m - a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
   }
  }
  forn(i, n){
   printf("%d ", ans[i]);
  }
  puts("");
 }
 return 0;
}
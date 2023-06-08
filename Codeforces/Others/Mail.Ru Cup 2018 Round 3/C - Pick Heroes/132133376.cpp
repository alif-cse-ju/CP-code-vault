#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e3+5;
const int N=1e6+5;
const int mod=1e9+7;
vector<pair<int,int>>V;
int m,n,prevs,done[M],other[M],score[M];
void myTurn() {
 if (prevs != -1) {
  int x = other[prevs];
  if (x && !done[x]) {
   done[x] = 1;
   printf("%d\n", x);
   fflush(stdout);
   return;
  }
 }
 for (auto& p : V) {
  if (!done[p.first]) {
   done[p.first] = 1;
   printf("%d\n", p.first);
   fflush(stdout);
   return;
  }
 }
  int mxValue = -1, which = 0;
 for (int i = 1; i <= 2 * n; i++) {
  if (!done[i] && mxValue < score[i]) {
   mxValue = score[i];
   which = i;
  }
 }
 done[which] = 1;
 printf("%d\n", which);
 fflush(stdout);
}
 void yourTurn() {
 scanf("%d", &prevs);
 done[prevs] = 1;
}
 void solve() {
 scanf("%d %d", &n, &m);
 for (int i = 1; i <= 2 * n; i++) {
  scanf("%d", &score[i]);
 }
 for (int i = 1; i <= m; i++) {
  int a, b;
  scanf("%d %d", &a, &b);
  if (score[a] < score[b]) swap(a, b);
  V.emplace_back(a, b);
  other[a] = b;
  other[b] = a;
 }
  int t;
 scanf("%d", &t);
 t--;
 prevs = -1;
 // t = 0, my.
 for (int i = 1; i <= 2 * n; i++) {
  if (t == 0) {
   myTurn();
  }
  else {
   yourTurn();
  }
  t ^= 1;
 }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
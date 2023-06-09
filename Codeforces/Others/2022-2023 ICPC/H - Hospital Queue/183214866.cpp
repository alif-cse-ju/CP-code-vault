//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <random>
#include <chrono>
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include <array>
#include <complex>
#include<iomanip>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))
 typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;
 typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL> VPL;
typedef vector<PII> VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef long double ld;
typedef unsigned long long ULL;
 //#define MAXN 1000
//#define MAXN2 MAXN*MAXN
#define MAXN 100
 //const LL MOD[2] = { 87420317, 1000000007 };
//const LL MOD = 1000000007;
const LL MOD = 998244353;
//const LL MOD = 547892069;
//const LL INF = 2000000000000000001LL; //2e18 + 1
 VI V[2003];
VI P;
int ans[2003];
VI order;
int n, m;
 void topSort() {
 VI in(n, 0);
 FORN(i, n) {
  for (int j : V[i]) in[j]++;
 }
 queue<int> Q;
 FORN(i, n) if (in[i] == 0) Q.push(i);
 while (!Q.empty()) {
  int u = Q.front();
  Q.pop();
   order.push_back(u);
  for (int j : V[u]) {
   in[j]--;
   if (in[j] == 0) {
    Q.push(j);
   }
  }
 }
}
 int Possible() {
 VI eP = P;
 VI Z(n + 1, 0);
 for (int i : order) {
  for (int j : V[i]) {
   eP[j] = MIN(eP[j], eP[i] - 1);
   if (eP[j] == 0) return 0;
  }
 }
 FORN(i, n) {
  Z[eP[i]]++;
 }
  int taken = 0;
 for (int i = 1; i <= n; i++) {
  taken += Z[i];
  if (taken > i) return 0;
 }
 return 1;
 }
 void solve(int ks) {
 scanf("%d %d", &n, &m);
 P = VI(n, 0);
 FORN(i, n) scanf("%d", &P[i]);
 FORN(i, m) {
  int a, b;
  scanf("%d %d", &a, &b);
  a--, b--;
  V[b].push_back(a);
 }
 topSort();
  FORN(i, n) {
  int back_up = P[i];
  {
   int lo = 1, hi = back_up;
   while (lo < hi) {
    int mid = (lo + hi) / 2;
    P[i] = mid;
    if (Possible()) {
     hi = mid;
    }
    else {
     lo = mid + 1;
    }
   }
   ans[i] = lo;
  }
  P[i] = back_up;
 }
 FORN(i, n) {
  printf("%d ", ans[i]);
 }
 printf("\n");
}
 void gen() {
}
 int main()
{
 double start_time = clock();
#ifdef LOCAL
 freopen("C:\\Home\\Contests\\F\\sample.in", "r", stdin);
 //freopen("C:\\Home\\Contests\\F\\0.out", "w", stdout);
#endif
  gen();
  if (0) {
  int T;
  scanf("%d", &T);
  //AIN(T, 1, 10);
  for (int ks = 1; ks <= T; ks++) {
   solve(ks);
   //if (ks % 1 == 0) fprintf(stderr, "%d done\n", ks);
  }
 }
 else {
  solve(1);
 }
  double end_time = clock();
 fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
 return 0;
}
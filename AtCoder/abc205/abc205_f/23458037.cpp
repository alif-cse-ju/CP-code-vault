#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace std;
using namespace atcoder;
int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> A(N), B(N), C(N), D(N);
  for (int i = 0; i < N; i++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--;
    B[i]--;
  }
  mf_graph<int> G(H + W + N * 2 + 2);
  int p = H + W + N * 2;
  for (int i = 0; i < H; i++){
    G.add_edge(p, i, 1);
  }
  for (int i = 0; i < W; i++){
    G.add_edge(H + i, p + 1, 1);
  }
  for (int i = 0; i < N; i++){
    int x = H + W + i * 2;
    int y = x + 1;
    G.add_edge(x, y, 1);
    for (int j = A[i]; j < C[i]; j++){
      G.add_edge(j, x, 1);
    }
    for (int k = B[i]; k < D[i]; k++){
      G.add_edge(y, H + k, 1);
    }
  }
  cout << G.flow(p, p + 1) << endl;
}
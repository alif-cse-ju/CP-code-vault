#include <bits/stdc++.h>
using namespace std;
#define N 2010
vector<int> tree[N];
int dfs(int i, int p) {
    int sm = 0, z = 0;
        for (int j : tree[i]) if (j != p) {
        int x = dfs(j, i);
        sm += x;
        if (x == 0)
            z++;
    }
        return sm + max(0, z - 1);
int main() {
    int num_tests;
    cin >> num_tests;
    for (int test = 0; test < num_tests; ++test) {
        int n;
        cin >> n;
                for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
                if (n == 1)
            cout << "0\n";
        else {
            int ans = n;
             for (int i = 1; i <= n; ++i)
                ans = min(ans, 1 + dfs(i, i));
                        cout << ans << '\n';
        }
                for (int i = 1; i <= n; ++i)
            tree[i].clear();
    }
}
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
#define TEST_CASES

void solve(int tc) {
    int n, m; cin >> n >> m;

    int edge[n + 1][n + 1] = {0};
    

    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);

        edge[u][v] = edge[v][u] = i;
    }

    int color[m + 1] = {0};


    if(m == n * (n - 1) / 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                color[edge[i][j]] = 3;
            }
        }

        for(int i = 1; i <= n; i++) {
            color[edge[i][1]] = color[edge[1][i]] = 1;
        }

        for(int i = 1; i <= n; i++) {
            color[edge[i][2]] = color[edge[2][i]] = 2;
        }

        color[edge[1][2]] = color[edge[2][1]] = 3;

        cout << 3 << endl;
        for(int i = 1; i <= m; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    } else {
        cout << 2 << endl;
        int v = 0;
        for(int i = 1; i <= n; i++) {
            int found = 0;
            for(int j = 1; j <= n; j++) if(i != j and !edge[i][j]) {
                found = j;
                break;
            }

            if(found) {
                v = i;
                break;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                color[edge[i][j]] = 2;
            }
        }

        for(int i = 1; i <= n; i++) {
            color[edge[i][v]] = color[edge[v][i]] = 1;
        }

        for(int i = 1; i <= m; i++) {
            cout << color[i] << " ";
        }

        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test = 1, tc = 0;

    #ifdef TEST_CASES
    cin >> test;
    #endif

    while(test--) {
        solve(++tc);
    }

    return 0;
}
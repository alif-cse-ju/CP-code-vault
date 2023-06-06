#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int inf = 1e14 ; 

int ar[405][405] ; 

void Min(int &a, int b) {
    if (b<a) a = b ; 
    return  ; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int n, m, ans = 0 ; 
    cin >> n >> m ; 
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            ar[i][j] = inf ; 
            if (i==j) ar[i][j] = 0 ; 
        }
    }
    int x, y, c ; 
    for (int i=1;i<=m;++i) {
        cin >> x >> y >> c ; 
        ar[x][y] = c ; 
    }
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                Min(ar[i][j], ar[i][k] + ar[k][j]) ; 
            }
        }
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                if (ar[i][j] < inf) {
                    ans += ar[i][j] ; 
                }
            }
        }
    }
    cout << ans << endl ; 
    return 0;
}


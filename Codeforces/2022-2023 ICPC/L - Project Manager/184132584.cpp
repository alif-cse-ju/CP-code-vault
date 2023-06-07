#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
const string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main() {
    cin.tie(0);
    iostream::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> ds(n, vector<char>(7));
    forn(i, n){
        int t;
        cin >> t;
        forn(_, t){
            string s;
            cin >> s;
            ds[i][find(days, days + 7, s) - days] = true;
        }
    }
    vector<int> h(m);
    forn(i, m) cin >> h[i];
    vector<vector<int>> a(k);
    forn(i, k){
        int p;
        cin >> p;
        a[i].resize(p);
        forn(j, p){
            cin >> a[i][j];
            --a[i][j];
        }
    }
    int j = 0;
    vector<int> ans(k, -1), lst(k);
    int done = 0;
    vector<map<int, int>> cur(7);
    vector<set<int>> wk(n);
    forn(i, k) forn(j, 7) if (ds[a[i][0]][j])
        ++cur[j][a[i][0]];
    forn(i, k)
        wk[a[i][0]].insert(i);
    for (int d = 1;; ++d){
        if (j < m && h[j] == d){
            ++j;
            continue;
        }
        int wd = (d - 1) % 7;
        vector<int> now, sv;
        for (auto it : cur[wd]) now.push_back(it.first);
        for (int x : now){
            forn(i, 7){
                auto it = cur[i].find(x);
                if (it != cur[i].end()){
                    if (it->second == 1)
                        cur[i].erase(it);
                    else
                        --it->second;
                }
            }
            int y = *wk[x].begin();
            sv.push_back(y);
            wk[x].erase(wk[x].begin());
        }
        forn(i, now.size()){
            int y = sv[i];
            ++lst[y];
            if (lst[y] == int(a[y].size())){
                ans[y] = d;
                ++done;
                continue;
            }
            wk[a[y][lst[y]]].insert(y);
            forn(j, 7) if (ds[a[y][lst[y]]][j])
                ++cur[j][a[y][lst[y]]];
        }
        if (done == k) break;
    }
    forn(i, k) cout << ans[i] << " ";
    cout << endl;
}
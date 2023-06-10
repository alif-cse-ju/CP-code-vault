#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
const int MAXN = 1000000;
char A[MAXN + 1];
int main()
{
    int tests;
    int sumN = 0;
    for (assert(scanf("%d", &tests) == 1 && 1 <= tests && tests <= 100); tests --;) {
        int m;
        assert(scanf("%s%d", &A, &m) == 2);
        int n = strlen(A);
        assert(1 <= n <= MAXN);
        for (int i = 0; i < n; ++ i) {
            assert('0' <= A[i] && A[i] <= '9');
        }
        sumN += n;
        assert(sumN <= 5 * MAXN);
        vector<int> pw(n + 1);
        pw[0] = 1 % m;
        for (int i = 1; i <= n; ++ i) {
            pw[i] = pw[i - 1] * 10 % m;
        }
        vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
        // [0, i), [i, n)
        for (int i = 0; i < n; ++ i) {
            prefix[i + 1] = (prefix[i] * 10 + A[i] - '0') % m;
        }
        for (int i = n - 1; i >= 0; -- i) {
            suffix[i] = (suffix[i + 1] + (A[i] - '0') * pw[n - 1 - i]) % m;
        }
// fprintf(stderr, "m = %d\n", m);
        vector<int> values;
        for (int i = 0; i < n; ++ i) {
            int value = (prefix[i] * pw[n - i - 1] + suffix[i + 1]) % m;
// fprintf(stderr, "\t%d\n", value);
            values.push_back(value);
        }
        int step = pw[n - 1];
        unordered_set<int> distinctValues(values.begin(), values.end());
        vector<vector<int>> adj(m);
        for (int i = 0; i < m; ++ i) {
            for (int x : distinctValues) {
                int j = (i * step + x) % m;
                adj[j].push_back(i);
// fprintf(stderr, "%d --> %d\n", j, i);
            }
        }
        vector<bool> mark(m, false);
        queue<int> q;
        q.push(0);
        mark[0] = true;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!mark[v]) {
                    mark[v] = true;
                    q.push(v);
                }
            }
        }
        int answer = 0;
        for (int v : values) {
            answer += mark[v];
        }
        printf("%d\n", answer);
    }
    return 0;
}
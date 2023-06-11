#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int cnt = 0, ncnt = 0;
        for(int i = 0; i < s.size(); i++) cnt += (s[i] == '0');
        if(!cnt) {
            cout << "0\n";
            continue;
        }
        for(int i = 0; i < cnt; i++) ncnt += (s[i] == '0');
        int ans = cnt - ncnt;
        for(int i = cnt; i < s.size(); i++) {
            ncnt -= (s[i - cnt] == '0');
            ncnt += (s[i] == '0');
            ans = min(ans, cnt - ncnt);
        }
        cout << ans << "\n";
    }
}
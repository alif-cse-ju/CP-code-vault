#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
        int n,s = 0;
        cin >> n;
        vector <int> a(n),b(n);
        for(int i=0;i<n;i++){
                cin >> a[i];
                s += a[i];
        }
        for(int j=0;j<n;j++){
                cin >> b[j];
        }
        vector < vector < int> > dp(n+1, vector <int> (s+1,-1e9));
        dp[0][0] = 0;
        for(int i=0;i<n;i++){
                for(int j=n;j>=1;j--){
                        for(int k=s;k>=min(a[i],b[i]);k--){
                                dp[j][k] = max(dp[j][k],dp[j-1][k-min(a[i],b[i])] + max(0,b[i]-a[i]));
                        }
                }
        }
        for(int i=n;i>=1;i--){
                int cur;
                bool fl = false;
                for(int j=0;j<=s;j++){
                        if(s-j <= dp[i][j]){
                                if(!fl){
                                        fl = true;
                                        cur = 2*(s-j);
                                        continue;
                                }
                                cur = min(cur, 2*(s-j));
                        }
                }
                if(!fl) cur = -1;
                cout << cur << " ";
        }
        cout << endl;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int tc;
        tc = 1;
        cin >> tc;
        for(int i=1;i<=tc;i++){
                solve();
        }
        return 0;
}
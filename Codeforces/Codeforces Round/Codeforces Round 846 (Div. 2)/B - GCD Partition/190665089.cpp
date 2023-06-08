#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define st first
#define nd second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N = 2e5 + 5;
ll a[N];
int n;
void solve(){
    cin >> n;
    ll ans = 0;
    ll sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    ll gone = 0;
    for(int i=1;i<n;i++){
        gone += a[i];
        sum -= a[i];
        ans = max(ans, __gcd(sum, gone));
    }
    cout << ans << "\n";
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
     return 0;
}
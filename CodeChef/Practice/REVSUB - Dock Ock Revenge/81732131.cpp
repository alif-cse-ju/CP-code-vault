#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)
#define endl '\n'
const ll MAX = INT_MAX;
const ll MIN = INT_MIN;
const ll MOD = 1e9 + 7;
ll ceil(ll a, ll b) {
    return (a + b - 1) / b; 
}
void solve(){
    ll n;
    cin >> n;
    vi a(n), b(n);
    rep(i,0,n){cin >> a[i];}
    rep(i,0,n){cin >> b[i];}
    vi pp1 = a, pp2 = b;
    sort(pp1.begin(), pp1.end());
    sort(pp2.begin(), pp2.end());
    if (pp1!=pp2){
        cout << -1 << endl;
        return;
    }
       ll az = 0, prev = 0, cnt = 0;
    rep(i,0,n){
        az += (a[i] - b[i]);
        if (az == 0){
            bool flag = true;
            rep(j,prev,i+1){
                if (a[j]!=b[i-j+prev]){
                    // cout << -1 << endl;
                    // return;
                    flag = false;
                }
            }
            if (flag){
                prev = i+1;
                cnt++;
            }
        }
            }
    if (az!=0){
        cout << -1 << endl;
    }
    else{
        rep(j,prev,n){
                if (a[j]!=b[n-j+prev]){
                    cout << -1 << endl;
                    return;
                    // flag = false;
                }
        }
        cout << cnt << endl;
    }
}
int main() {
    FAST;
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
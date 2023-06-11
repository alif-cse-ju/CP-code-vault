#include<bits/stdc++.h>
# define pb push_back 
#define pii pair<int, int>
#define mp make_pair
# define ll long long int
using namespace std;
  const int maxm = 1e5, maxtm = 1e6, maxx = 1e9, maxy = 1e9, maxn = 1e9;
vector<pii> v;
int main()
{   
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int tm = 0;
    int maxitr = 0;
    ll n; int m;
    int x, y;
    while(t--){
        v.clear();
        cin >> n >> m;
        tm += m;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            v.pb({x, y});
        }
        sort(v.begin(), v.end(), greater<pii>());
        int itr = 0;
        ll d = 1, ans = 0, S = n;
        for(pii p : v){
            if(d <= n)d = (d * p.second) / __gcd(d, (ll)p.second);
            ans += p.first * (S - n / d); S = n / d; 
            itr++;
            if(S == 0)break;
        }
        maxitr = max(maxitr, itr);
        cout << ans << endl;
    }
    assert(tm <= maxtm);
} 
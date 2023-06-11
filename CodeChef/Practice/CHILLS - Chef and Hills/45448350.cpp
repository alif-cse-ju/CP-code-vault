#include<bits/stdc++.h>
# define pb push_back 
#define pii pair<int, int>
#define mp make_pair
# define ll long long int
using namespace std;
 const int maxn = 1e5, maxk = 1e5, maxt = 10, maxv = 1e9, minv = 1;
int main()
{   
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n + 1]; a[0] = 0;
        for(int i = 1; i <= n; i++)cin >> a[i];
        int l1 = -1, l2 = -1;
        if(n % 2 == 0){
            l1 = a[n / 2] - (k + 1) / 2 + 1;
            l2 = a[n / 2 + 1] - (k + 1) / 2 + (k % 2);
        }else{
            l1 = a[(n + 1) / 2] - (k + 1) / 2 + 1;
            l2 = a[(n + 1) / 2] - (k + 1) / 2 + (k % 2);
        }       
        ll val1 = 0, val2 = 0;
        for(int i = 1; i <= n; i++){
            val1 += max(abs(a[i] - l1), abs(a[i] - (l1 + k - 1)));
            val2 += max(abs(a[i] - l2), abs(a[i] - (l2 + k - 1)));
        }
        ll ans = min(val1, val2);
        cout << ans << endl;
    }
} 
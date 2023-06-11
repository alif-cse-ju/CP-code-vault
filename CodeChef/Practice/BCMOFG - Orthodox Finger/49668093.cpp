#include <bits/stdc++.h>
#define ll long long int 
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
#define ffs fflush(stdout);
#define sz(x) (ll)x.size()
using namespace std;
void solve()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
         cin>>arr[i];
    }
   unordered_map<int, int> hash;
   for (int i = 0;i < n; ++i) {
      hash[arr[i]]++;
   }
   int maxFrequency = 0;
   for (auto elem : hash) {
      if (elem.second > maxFrequency) {
         maxFrequency = elem.second;
      }
   }
   cout<<(n-maxFrequency);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
        solve();
          }
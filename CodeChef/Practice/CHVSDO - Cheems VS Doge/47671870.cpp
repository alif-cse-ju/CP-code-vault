#include <bits/stdc++.h>
#include<unordered_map>
#define ll long long int
#define endl "\n"
// Header files, namespaces,
// macros as defined above
#define debug(a) cout << a << endl;
using namespace std;
// Important header files  
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll inf=10e15;
void I_O()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("T:\\input_output\\input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("T:\\input_output\\output.txt", "w", stdout);
    #endif
}
const ll mod=1000000007;
ll subsetSum(ll a[], ll n, ll sum)
{
    // Initializing the matrix
    ll tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    tab[0][0] = 1;
    for (ll i = 1; i <= sum; i++)
        tab[0][i] = 0;
    for (ll i = 1; i <= n; i++)
        tab[i][0] = 1;
     for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = (tab[i - 1][j]);
            else
            {
                tab[i][j] = (tab[i - 1][j] + tab[i - 1][j - a[i - 1]])%mod;
            }
        }
    }
      return (tab[n][sum]%mod);
}
ll primeFactors(int n)
{
    // Print the number of 2s that divide n
    ll count=0;
    if(n%2==0){
        count++;
    }
    while (n % 2 == 0)
    {
        n = n/2;
    }
     // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0){
            count++;
        }
        while (n % i == 0)
        {
                        n = n/i;
        }
    }
     // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        count++;
        return count;
}
 int main(){
    I_O();
    ll l,r,s;
    cin>>l>>r>>s;
        ll arr[r-l+2];
    ll k=0;
    for(int i=l;i<=r;i++){
        arr[k]=primeFactors(i);
        k++;
    }
    sort(arr,arr+k);
      if(l>1){
        cout<<subsetSum(arr,k,s)%mod<<endl;
    }
    else{
    cout<<(subsetSum(arr,k,s)*2)%mod<<endl;
    }
    }
 
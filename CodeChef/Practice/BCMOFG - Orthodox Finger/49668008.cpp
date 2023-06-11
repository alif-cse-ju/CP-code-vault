#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n; cin>>n;
    ll a[n];
    for(ll i=0;i<n; i++){
        cin>>a[i];
    }
    unordered_map<ll, ll> mp;
    for (ll i=0; i<n; i++)
        mp[a[i]]++;
    ll maxi = 0;
    for (auto i : mp){
        if (maxi < i.second){
            maxi = i.second;
        }
    }
    cout<<n-maxi<<'\n';
    return 0;
}
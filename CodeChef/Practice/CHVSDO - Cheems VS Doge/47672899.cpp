    // author: sharad12arse
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define gcd __gcd
#define INF (ll)1e15
const ll mod=1e9+7;
void solve(){
    ll l,r,s;
    cin>>l>>r>>s;
    vector<ll> arr;
    ll temp;
    int cnt=0;
    for(int i=l;i<=r;i++){
        temp=i;
        set<int> a;
        for(int j=2;j<=sqrt(temp);j++){
            while(temp%j==0){
                a.insert(j);
                temp/=j;
            }
        }
        if(temp>1){
            a.insert(temp);
        }
        arr.push_back(a.size());
    }
    vector<vector<ll> > dp(arr.size()+1,vector<ll> (s+1,0ll));
    for(int i=0;i<=arr.size();i++){
        for(int j=0;j<=s;j++){
            if(i==0||j==0){
                if(j==0){
                    dp[i][j]=1;
                }
            }else{
                if(j>=arr[i-1]&&dp[i-1][j-arr[i-1]]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
            dp[i][j]%=mod;
        }
    }
    if(l==1){
        dp[arr.size()][s]*=2ll;
    }
    cout<<dp[arr.size()][s]%mod<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
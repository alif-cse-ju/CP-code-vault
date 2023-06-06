#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    dp[1]=1;
    for(ll i=2;i<=100000;i++){
        for(ll j=1;j*j<=i;j++){
            dp[i]+=dp[j];
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        ll X;cin>>X;
        if(X<=100000){
            cout<<dp[X]<<"\n";
            continue;
        }
        if(X<=10000000000LL){
            ll res=0;
            for(ll j=1;j*j<=X;j++) res+=dp[j];
            cout<<res<<"\n";
            continue;
        }
        ll res=0;
        for(ll j=1;j<=100000;j++) res+=dp[j];
        for(ll j=1;j<=100000;j++){
            ll left=j*j,right=floor(sqrt(X));
            if(right*right>X) right--;
            chmax(left,100001LL);
            if(left>right) break;
            res+=(right-left+1)*dp[j];
        }
        
        cout<<res<<"\n";
    }
}


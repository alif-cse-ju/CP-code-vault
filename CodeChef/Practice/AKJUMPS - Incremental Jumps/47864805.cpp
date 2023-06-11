#include "bits/stdc++.h"
#define ll long long int
#define oo 1000000000000000000
#define forr(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
#define unique(v) sort(all(v)); v.resize(distance(v.begin(),unique(all(v))))
#define eb emplace_back
#define FF first
#define SS second
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define popcount(x) __builtin_popcount(x)
using namespace std;
template<typename T>
ostream &operator<<(ostream &output,const vector<T> &v){ 
    if(v.empty()) return output;
    for(int i=0;i<v.size()-1;i++) output << v[i] <<" ";
    output << v.back();
    return output;
}
template<typename T>
istream &operator>>(istream &input,vector<T> &v){ 
    for(auto &i: v) cin >> i;
    return input;            
}
int spf[200010];
void pre_prime(){
    forr(i,200010) spf[i] = i;
    for(int i=2;i<=200000;i++){
        if(spf[i]==i){
            for(int j=2;j*i<=200000;j++){
                if(spf[j*i] == j*i) spf[i*j] = i;
            }
        }
    }
}
int dcount(int x){
    return 1 + (log2(x)/log2(10));
}
vector<int> sp;
bool check(int x){
    int cnt = 1 + (log2(x)/log2(10));
    int cnt1 = 0;
    while(x>1){
        int f = spf[x];
        cnt1+=dcount(f);
        int gg = 0;
        while(x%f==0) x/=f , gg++;
        if(gg > 1) cnt1 += dcount(gg);
    }
    return cnt1 == cnt;
}
void pre(){
    sp.eb(1);
    for(int i=2;i<=200000;i++){
        if(check(i)) sp.eb(i);
    }
}
void __sol(){
    int a,b; cin >> a >> b;
    int x = b - a;
    int ans = 0;
    while(x>0){
        auto it = upper_bound(all(sp),x);
        it--;
        x -= *it;
        ans++;
    }
    cout << ans<<"\n";
    return;
}
int main(){ 
    pre_prime();
    pre();
    fastio;
    int tc=1; cin >> tc;
    while(tc--) __sol();
    return 0;
}
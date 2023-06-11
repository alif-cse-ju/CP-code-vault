#include <bits/stdc++.h>
using namespace std;
#define sync {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define rep(n) for(int i = 0;i<n;i++)
#define rep1(a,b) for(int i = a;i<b;i++)
#define int long long int
#define mod 1000000007
int n, x;
void solve()
{
    cin>>n>>x;
    if(n==1){
        cout<<x;
        return;
    }
    int y = 0;
    int ans[n];
    for(int i = 0; i<n-1; i++){
        ans[i] = i;
        y ^= i;
    }
    int z = y^x;
    int temp = 1<<18;
    if(z>=n-1 && z<=500000){
        ans[n-1] = z;
    }
    else{
        ans[n-1] = z^temp;
        if((ans[n-2] ^ temp) == ans[n-1]){
            ans[0] ^= temp;
        }
        else{
            ans[n-2] ^= temp;
        }
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<' ';
    }
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        sync;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}
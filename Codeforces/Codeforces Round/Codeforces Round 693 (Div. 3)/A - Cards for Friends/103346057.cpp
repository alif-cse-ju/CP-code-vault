#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=5e5+5;
const int mod=1e9+7;
long long Solve(long long x,long long y)
    if(x%2 == 0)return 2ll*Solve(x/2ll,y);
    if(y%2 == 0)return 2ll*Solve(x,y/2ll);
    return 1;
int main()
    FAST();
    int t;
    long long a,b,n,ans;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        ans=Solve(a,b);
        if(ans >= n)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
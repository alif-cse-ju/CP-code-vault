#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,x=0,y=1,z,ans=0;
    cin >> n;
    n=n+n-1;
    if(n < 9)
    {
        n=(n+1)/2;
        cout << (n*(n-1))/2;
        return 0;
    }
    while(x*10+9 <= n)
    {
        x=x*10+9;
        y=y*10;
    }
    for(long long i=0;i*y+x <= n ;i++)
    {
        z=i*y+x;
        ans+=min(z/2,(n+1)/2-z/2);
    }
    cout << ans;
    return 0;
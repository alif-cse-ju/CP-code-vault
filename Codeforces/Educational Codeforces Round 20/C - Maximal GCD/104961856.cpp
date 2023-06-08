#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long Check(long long m,long long n)
    return ((n*(n+1))/2)*m;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,k,n,mx,ans=0;
    cin >> n >> k;
    if(k > 141420  || Check(1,k) > n)
    {
        cout << "-1";
        return 0;
    }
    mx=n/Check(1,k);
    for(i=1;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            if(i <= mx  &&  Check(i,k) <= n)ans=max(ans,i);
            if(n/i <= mx  &&  Check(n/i,k) <= n)ans=max(ans,n/i);
        }
    }
    if(ans == 0)cout << "-1";
    else
    {
        for(i=1;i<k;i++)
        {
            cout << i*ans << ' ';
            n-=i*ans;
        }
        cout << n;
    }
    return 0;
}
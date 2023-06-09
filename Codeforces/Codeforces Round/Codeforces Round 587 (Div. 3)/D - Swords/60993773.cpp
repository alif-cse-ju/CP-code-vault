#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,n;
    cin >> n;
    int a[n+3];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    long long sum=a[n-1]-a[n-2];
    int gcd=sum;
    for(i=n-3;i>=0;i--)
    {
        sum+=(a[n-1]-a[i]);
        gcd=__gcd(gcd,a[n-1]-a[i]);
    }
    cout << sum/gcd << ' ' << gcd;
    return 0;
#include<bits/stdc++.h>
using namespace std;
int main()
    long long int i,n,ans=0LL;
    cin >> n;
    for(i=2;i<n;i++)ans+=(i * (i+1LL));
    cout << ans;
    return 0;
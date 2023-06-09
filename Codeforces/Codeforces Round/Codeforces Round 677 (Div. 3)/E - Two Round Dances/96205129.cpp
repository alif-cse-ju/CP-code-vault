#include<bits/stdc++.h>
using namespace std;
long long fact[22];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    long long ans;
    cin >> n;
    fact[0]=fact[1]=1;
    for(i=2;i<=n;i++)fact[i]=fact[i-1]*i;
    ans=(fact[n]/fact[n/2])/fact[n/2];
    ans=ans*fact[n/2-1]*fact[n/2-1];
    cout << ans/2;
    return 0;
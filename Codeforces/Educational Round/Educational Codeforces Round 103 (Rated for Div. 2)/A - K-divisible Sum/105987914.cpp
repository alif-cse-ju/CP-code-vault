#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << ((((n+k-1)/k)*k)+n-1)/n << '\n';
    }
    return 0;
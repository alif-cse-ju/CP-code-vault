#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(n%2 == 0)n/=2;
        if(n == 1)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
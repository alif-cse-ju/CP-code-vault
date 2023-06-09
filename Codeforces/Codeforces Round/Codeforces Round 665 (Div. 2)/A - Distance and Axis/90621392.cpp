#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n < k)cout << k-n << '\n';
        else cout << ((n-k) & 1) << '\n';
    }
    return 0;
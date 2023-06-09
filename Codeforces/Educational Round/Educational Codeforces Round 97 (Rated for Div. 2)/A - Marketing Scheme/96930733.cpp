#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,r,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        if(l*2 <= r)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
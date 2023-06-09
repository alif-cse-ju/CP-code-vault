#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << n-1 << '\n';
        for(i=2;i<=n;i++)cout << i << ' ';
        cout << '\n';
    }
    return 0;
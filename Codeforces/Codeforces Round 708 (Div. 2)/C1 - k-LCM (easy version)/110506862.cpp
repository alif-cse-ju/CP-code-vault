#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n%3 == 0)cout << n/3 << ' ' << n/3 << ' ' << n/3 << '\n';
        else if(n & 1)cout << "1 " << n/2 << ' ' << n/2 << '\n';
        else
        {
            if((n/2) & 1)cout << "2 " << n/2-1 << ' ' << n/2-1 << '\n';
            else cout << n/4 << ' ' << n/4 << ' ' << n/2 << '\n';
        }
    }
    return 0;
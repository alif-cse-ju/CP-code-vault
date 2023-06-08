#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll n,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n < 7)cout << "15\n";
        else
        {
            if(n%6 == 0)cout << (n/6)*15 << '\n';
            else if(n%6 <= 2)cout << (n/6-1)*15+20 << '\n';
            else if(n%6 <= 4)cout << (n/6-1)*15+25 << '\n';
            else cout << (n/6+1)*15 << '\n';
        }
    }
    return 0;
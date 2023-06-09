#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long a,b,c,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        cout << a+b+c-1 << '\n';
    }
    return 0;
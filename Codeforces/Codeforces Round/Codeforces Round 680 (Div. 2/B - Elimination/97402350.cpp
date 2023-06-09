#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,c,d,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        cout << max(a+b,c+d) << '\n';
    }
    return 0;
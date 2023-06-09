#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%4 > 0)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
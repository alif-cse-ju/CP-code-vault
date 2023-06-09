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
        if(n > 30  &&  n-30 != 6  &&  n-30 != 10  &&  n-30 != 14)cout << "YES\n6 10 14 " << n-30 << '\n';
        else if(n > 31  &&  n-31 != 6  &&  n-31 != 10  &&  n-31 != 15)cout << "YES\n6 10 15 " << n-31 << '\n';
        else if(n > 35  &&  n-35 != 6  &&  n-35 != 14  &&  n-35 != 15)cout << "YES\n6 14 15 " << n-35 << '\n';
        else if(n > 39  &&  n-39 != 10  &&  n-39 != 14  &&  n-39 != 15)cout << "YES\n10 14 15" << n-39 << '\n';
        else cout << "NO\n";
    }
    return 0;
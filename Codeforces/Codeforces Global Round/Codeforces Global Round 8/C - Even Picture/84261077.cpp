#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n;
    cin >> n;
    cout << 3*n+4;
    cout << "\n1 0\n2 0\n";
    for(i=1;i<=n;i++)
    {
        cout << i << ' ' << i << '\n';
        cout << i+1 << ' ' << i << '\n';
        cout << i+2 << ' ' << i << '\n';
    }
    cout << i << ' ' << i << '\n';
    cout << i+1 << ' ' << i << '\n';
    return 0;
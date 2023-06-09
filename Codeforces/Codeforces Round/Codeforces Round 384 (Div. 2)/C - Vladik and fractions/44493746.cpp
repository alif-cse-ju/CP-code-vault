#include<bits/stdc++.h>
using namespace std;
int main()
    int n;
    cin >> n;
    if (n > 2)
    {
        cout << n << " " << n + 1 << " " << n * (n + 1);
    }
    else if (n == 2)
    {
        cout << 2 << " " << 3 << " " << 6 ;
    }
    else
    {
        cout << -1;
    }
    return 0;
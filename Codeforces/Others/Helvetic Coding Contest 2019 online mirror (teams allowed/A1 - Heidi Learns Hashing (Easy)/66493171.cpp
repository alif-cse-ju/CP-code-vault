#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long x;
    cin >> x;
    if(x & 1  &&  x > 3)cout << 1 << ' ' << (x-3)/2;
    else cout << "NO";
    return 0;
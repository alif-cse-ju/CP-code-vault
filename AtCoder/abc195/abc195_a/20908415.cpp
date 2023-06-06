#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,h;
    cin >> m >> h;
    if(h%m)cout << "No";
    else cout << "Yes";
    return 0;
}
//
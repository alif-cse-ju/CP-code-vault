#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << min(min(a,b),min(c,d));
    return 0;
}
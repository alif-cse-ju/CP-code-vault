#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int d,s,t;
    cin >> d >> t >> s;
    if(d/s+(d%s > 0) <= t)cout << "Yes";
    else cout << "No";
    return 0;
}

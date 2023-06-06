#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max(max(a*c,b*c),max(a*d,b*d));
    return 0;
}

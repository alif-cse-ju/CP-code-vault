#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cout << ((x/2)*(y/2))+(((x+1)/2)*((y+1)/2)) << '\n';
    }
    return 0;
}
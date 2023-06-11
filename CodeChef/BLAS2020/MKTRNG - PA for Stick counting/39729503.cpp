#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 0)cout << "-1\n";
        else if(n == 1)cout << "3\n";
        else if(n == 2)cout << "5\n";
        else cout << 2*n << '\n';
    }
    return 0;
}
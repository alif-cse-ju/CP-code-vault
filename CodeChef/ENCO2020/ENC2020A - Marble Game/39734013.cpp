#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
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
        if(n == 3)cout << "A\n";
        else cout << "B\n";
    }
    return 0;
}
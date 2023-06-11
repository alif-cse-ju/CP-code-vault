#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int H,t,X;
    cin >> t;
    while(t--)
    {
        cin >> H >> X;
        if(H >= X)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
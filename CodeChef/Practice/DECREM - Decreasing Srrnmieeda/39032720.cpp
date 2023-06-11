#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,r,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        if(r >= (l << 1))cout << "-1\n";
        else cout << r << '\n';
    }
    return 0;
}
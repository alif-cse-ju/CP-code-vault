#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,odd,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        odd=0;
        while(n--)cin >> x, odd+=(x & 1);
        cout << odd/2 << '\n';
    }
    return 0;
}
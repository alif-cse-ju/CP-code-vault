#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,ans;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        while(n)
        {
            ++ans;
            n/=2;
        }
        cout << ans << '\n';
    }
    return 0;
}
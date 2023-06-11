#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        while(n)
        {
            if(n & 1)++ans;
            n/=2;
        }
        cout << ans << '\n';
    }
    return 0;
}
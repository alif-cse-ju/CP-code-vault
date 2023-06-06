#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,ans=0;
    cin >> n;
    if(n%2 == 0)
    {
        n/=2;
        while(n > 0)ans+=n/5,n/=5;
    }
    cout << ans;
    return 0;
}

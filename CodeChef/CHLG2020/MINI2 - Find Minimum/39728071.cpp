#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long i,n,rt,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        rt=sqrt(n);
        ans=n+1;
        for(i=2;i<=rt;i++)
        {
            if(n%i == 0  &&  i != n/i)ans=min(ans,i+n/i);
        }
        cout << ans << '\n';
    }
    return 0;
}
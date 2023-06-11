#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long i,n,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        for(i=1; ;i++)
        {
            if((i*(i+1))/2 <= n)ans+=i*i;
            else break;
        }
        ans+=(n-((i*(i-1))/2))*i;
        cout << ans << '\n';
    }
}
//
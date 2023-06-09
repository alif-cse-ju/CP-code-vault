#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,t,ans,check;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=n-1;
        l=min(n,100000);
        for(i=2;i<=l;i++)
        {
            check=(n/i)+(n%i > 0)+i-2;
            ans=min(ans,check);
        }
        cout << ans << '\n';
    }
    return 0;
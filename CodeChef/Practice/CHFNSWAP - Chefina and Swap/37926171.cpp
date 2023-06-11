#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long ans,cnt,m,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(((n+1)/2) & 1)cout << "0\n";
        else
        {
            cnt=(n*(n+1))/4;
            m=sqrt(2*cnt)+1;
            while((m*(m+1))/2 > cnt)--m;
            cnt-=(m*(m+1))/2;
            ans=n-m;
            if(!cnt)ans+=(m*(m-1))/2+((n-m)*(n-m-1))/2;
            cout << ans << '\n';
        }
    }
    return 0;
}
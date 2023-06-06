#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c,i,n,ans=LLONG_MAX;
    cin >> n;
    for(i=59;i>=0;i--)
    {
        b=(1ll << i);
        if(b > n)continue;
        a=n/b,c=n%b;
        ans=min(ans,a+c+i);
    }
    cout << ans;
    return 0;
}
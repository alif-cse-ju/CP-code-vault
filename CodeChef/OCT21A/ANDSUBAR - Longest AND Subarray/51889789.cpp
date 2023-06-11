#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=1;
        for(i=1;i<30;i++)ans=max(ans,min((1 << i),n-(1 << i)+1));
        cout << ans << '\n';
    }
    return 0;
}
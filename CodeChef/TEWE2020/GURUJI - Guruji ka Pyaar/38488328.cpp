#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        for(i=0;i<31;i++)
        {
            x=(1 << i);
            ++ans;
            if(n <= x)break;
            n-=x;
        }
        cout << ans << '\n';
    }
    return 0;
}
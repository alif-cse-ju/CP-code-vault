#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int n,t,x,y;
    long long ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> y;
        ans=0,n--;
        while(n--)
        {
            cin >> x;
            ans+=abs(x-y)-1,y=x;
        }
        cout << ans << '\n';
    }
    return 0;
}
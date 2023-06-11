#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int k,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> k;
        while(n--)
        {
            cin >> x;
            if(x > k)ans+=x-k;
        }
        cout << ans << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int n,s,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> s >> n;
        if(s <= n)
        {
            ans=1;
            if((s & 1)  &&  s > 1)++ans;
        }
        else
        {
            ans=s/n;
            s%=n;
            if(s > 0)
            {
                ++ans;
                if((s & 1)  &&  s > 1)++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
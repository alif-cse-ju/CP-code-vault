#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL a,b,c,d,ans;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d;
        ans=b;
        a=max(0LL,a-b);
        if(a == 0)cout << ans << '\n';
        else
        {
            d=c-d;
            if(d < 1)cout << "-1\n";
            else
            {
                d=(a+d-1)/d;
                ans+=c*d;
                cout << ans << '\n';
            }
        }
    }
    return 0;
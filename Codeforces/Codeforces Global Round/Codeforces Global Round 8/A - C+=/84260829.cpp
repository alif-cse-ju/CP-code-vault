#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int x,y,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> n;
        ans=0;
        if(x > y)swap(x,y);
        while(y <= n)
        {
            x+=y;
            ++ans;
            if(x > y)swap(x,y);
        }
        cout << ans << '\n';
    }
    return 0;
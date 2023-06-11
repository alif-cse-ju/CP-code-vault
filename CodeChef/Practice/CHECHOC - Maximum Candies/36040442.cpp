#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int m,n,t,x,y,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y;
        n*=m;
        if(n > 1)x=min(x,y);
        y=min(y,2*x);
        ans=((n+1)/2)*x+(n/2)*(y-x);
        cout << ans << '\n';
    }
    return 0;
}
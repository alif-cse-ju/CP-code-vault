#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,x,x1,x2,y1,y2,z1,z2,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        x=min(z1,y2);
        ans+=x*2,z1-=x,y2-=x;
        x=min(z1,z2);z1-=x,z2-=x;
        x=min(y1,y2);y1-=x,y2-=x;
        x=min(z2,x1);z2-=x,x1-=x;
        x=min(y1,x2);y1-=x,x2-=x;
        x=min(y1,z2);
        ans-=x*2;
        cout << ans << '\n';
    }
    return 0;
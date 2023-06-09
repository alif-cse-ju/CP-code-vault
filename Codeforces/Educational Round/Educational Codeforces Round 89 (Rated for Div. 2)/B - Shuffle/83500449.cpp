#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int l,m,n,t,r,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> m;
        y=x;
        while(m--)
        {
            cin >> l >> r;
            if(r < x  ||  l > y)continue;
            x=min(l,x),y=max(r,y);
        }
        cout << y-x+1 << '\n';
    }
    return 0;
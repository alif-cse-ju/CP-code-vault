#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int x,y,t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        x=(x/9)+(x%9 > 0);
        y=(y/9)+(y%9 > 0);
        if(x >= y)cout << "1 " << y << '\n';
        else cout << "0 " << x << '\n';
    }
    return 0;
}
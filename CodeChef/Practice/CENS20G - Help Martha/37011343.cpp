#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    bool valX,valY;
    int a,b,t,q,x,y,down,left,right,up;
    cin >> t;
    while(t--)
    {
        cin >> s;
        down=left=right=up=0;
        for(char c : s)
        {
            if(c == 'U')++up;
            else if(c == 'D')++down;
            else if(c == 'L')++left;
            else ++right;
        }
        cin >> a >> b >> q;
        while(q--)
        {
            cin >> x >> y;
            x-=a,y-=b;
            valX=valY=0;
            if(x > 0)
            {
                if(x <= right)valX=1;
            }
            else if(x < 0)
            {
                if(abs(x) <= left)valX=1;
            }
            else valX=1;
            if(y > 0)
            {
                if(y <= up)valY=1;
            }
            else if(y < 0)
            {
                if(abs(y) <= down)valY=1;
            }
            else valY=1;
            if(valX  &&  valY)cout << "YES " << abs(x)+abs(y) << '\n';
            else cout << "NO\n";
        }
    }
    return 0;
}
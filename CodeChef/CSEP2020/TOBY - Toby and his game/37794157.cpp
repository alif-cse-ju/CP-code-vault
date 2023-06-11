#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        x=y=0;
        for(i=0;i<l;i++)
        {
            if(s[i] == 'U')++y;
            else if(s[i] == 'D')--y;
            else if(s[i] == 'R')++x;
            else --x;
        }
        cout << l-abs(x)-abs(y) << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1024+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int curHr,curMn,dhonerHr,dhonerMn,hr,mn,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> hr >> mn >> s;
        curHr=(s[0]-'0')*10+(s[1]-'0');
        curMn=(s[3]-'0')*10+(s[4]-'0');
        do
        {
            if(curMn == mn)
            {
                curMn=0;
                ++curHr;
                curHr%=hr;
            }
            x=curMn%10,y=curMn/10;
            if(!x  ||  x == 1  ||  x == 8)dhonerHr=x*10;
            else if(x == 2)dhonerHr=50;
            else if(x == 5)dhonerHr=20;
            else dhonerHr=500;
            if(!y  ||  y == 1  ||  y == 8)dhonerHr+=y;
            else if(y == 2)dhonerHr+=5;
            else if(y == 5)dhonerHr+=2;
            else dhonerHr=500;
            x=curHr%10,y=curHr/10;
            if(!x  ||  x == 1  ||  x == 8)dhonerMn=x*10;
            else if(x == 2)dhonerMn=50;
            else if(x == 5)dhonerMn=20;
            else dhonerMn=500;
            if(!y  ||  y == 1  ||  y == 8)dhonerMn+=y;
            else if(y == 2)dhonerMn+=5;
            else if(y == 5)dhonerMn+=2;
            else dhonerMn=500;
             if(dhonerHr < hr  &&  dhonerMn < mn)break;
        }
        while(++curMn);
        if(curHr < 10)cout << '0';
        cout << curHr << ':';
        if(curMn < 10)cout << '0';
        cout << curMn << '\n';
    }
    return 0;
}
//
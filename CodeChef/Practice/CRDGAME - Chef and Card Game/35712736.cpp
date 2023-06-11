#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    string s;
    int n,t,x,y,cnt1,cnt2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt1=cnt2=0;
        while(n--)
        {
            x=y=0;
            cin >> s;
            for(char c : s)x+=c-'0';
            cin >> s;
            for(char c : s)y+=c-'0';
            if(x > y)++cnt1;
            else if(y > x)++cnt2;
            else ++cnt1,++cnt2;
        }
        if(cnt1 > cnt2)cout << "0 " << cnt1 << '\n';
        else if(cnt1 < cnt2)cout << "1 " << cnt2 << '\n';
        else cout << "2 " << cnt1 << '\n';
    }
    return 0;
}
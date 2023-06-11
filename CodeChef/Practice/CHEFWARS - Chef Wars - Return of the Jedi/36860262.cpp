#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int h,p,t;
    cin >> t;
    while(t--)
    {
        cin >> h >> p;
        while(p > 0)
        {
            h-=p;
            if(h <= 0)break;
            p/=2;
        }
        if(p)cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
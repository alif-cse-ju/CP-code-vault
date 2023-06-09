#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL x,y,cnt;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cnt=0;
        while(x%2 == 0)x/=2,++cnt;
        while(y%2 == 0)y/=2,--cnt;
        if(x != y)cout << "-1\n";
        else
        {
            cnt=abs(cnt);
            cout << cnt/3+(cnt%3 > 0) << '\n';
        }
    }
    return 0;
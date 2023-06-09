#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,x1,x2,y1,y2;
    cin >> t;
    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2)cout << abs(y1-y2) << '\n';
        else if(y1 == y2)cout << abs(x1-x2) << '\n';
        else cout << abs(x1-x2)+abs(y1-y2)+2 << '\n';
    }
    return 0;
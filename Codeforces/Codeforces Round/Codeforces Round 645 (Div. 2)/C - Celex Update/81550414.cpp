#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL x,x1,x2,y,y1,y2;
    cin >> t;
    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x=x2-x1,y=y2-y1;
        cout << x*y+1 << '\n';
    }
    return 0;
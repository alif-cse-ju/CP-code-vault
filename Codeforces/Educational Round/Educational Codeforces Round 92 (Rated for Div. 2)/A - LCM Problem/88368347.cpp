#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(2*x > y)cout << "-1 -1\n";
        else cout << x << ' ' << 2*x << '\n';
    }
    return 0;
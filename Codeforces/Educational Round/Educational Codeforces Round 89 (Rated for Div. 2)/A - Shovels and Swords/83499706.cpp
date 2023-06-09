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
        cout << min((x+y)/3,min(x,y)) << '\n';
    }
    return 0;
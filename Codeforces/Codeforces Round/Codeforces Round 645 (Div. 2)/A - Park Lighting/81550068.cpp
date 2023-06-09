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
        cout << (x*y+1)/2 << '\n';
    }
    return 0;
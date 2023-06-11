#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,x;
    string a,b,c;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> a >> b;
        if(b == "H")c="E";
        else c="H";
        if(a == "R")x=n-x+1;
        cout << x << ' ';
        if(x & 1)cout << b << '\n';
        else cout << c << '\n';
    }
    return 0;
}
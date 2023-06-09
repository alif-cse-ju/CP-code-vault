#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int a,b,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a < b)swap(a,b);
        if(2*b < a)cout << a*a << '\n';
        else cout << (b+b)*(b+b) << '\n';
    }
    return 0;
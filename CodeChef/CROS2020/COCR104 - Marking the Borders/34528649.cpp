#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int a,b,l,t,r;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> l >> r;
        l=max(0,l-1);
        l=(l/(a+b))*2+(l%(a+b) >= a);
        r=(r/(a+b))*2+(r%(a+b) >= a);
        cout << r-l << '\n';
    }
    return 0;
}